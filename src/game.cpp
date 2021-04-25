#include "game.h"
#include "board.h"
#include "ball.h"
#include <iostream>
#include <future>
#include <thread>
#include <memory>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height) : ball(grid_width, grid_height) {
	// Initalize boards with unique ptrs
	for(int i = 0; i < numBoards; i++) {
		std::unique_ptr<Board> board = std::make_unique<Board>(grid_width, grid_height, 5, i);
		boards.emplace_back(std::move(board));
	}
}

void Game::Run(Controller const &controller, Renderer &renderer,
                std::size_t target_frame_duration) {
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;
    bool running = true;

    while (running) {
		frame_start = SDL_GetTicks();

		// Input, Update, Render - the main game loop.
		controller.HandleInput(running, boards);
		Update();
		renderer.Render(boards, ball);

		frame_end = SDL_GetTicks();

		// Keep track of how long each loop through the input/update/render cycle
		// takes.
		frame_count++;
		frame_duration = frame_end - frame_start;

		// After every 15 seconds, increase speed.
		if (frame_end - title_timestamp >= 15000) {
			ball.speed -= 1;
			title_timestamp = frame_end;
		}

		// If the time for this frame is too small (i.e. frame_duration is
		// smaller than the target ms_per_frame), delay the loop to
		// achieve the correct frame rate.
		if (frame_duration < target_frame_duration) {
			SDL_Delay(target_frame_duration - frame_duration);
		}
    }
}

void Game::Update() {
	// Check if one of both players (boards) has already lost
	for(auto it = boards.begin(); it != boards.end(); ++it) {
		if((*it)->state == Board::State::loss) {
			return;
		}
	}

	// Run board update inside of new task		
	std::future<void> ftr = std::async(std::launch::async, 
		[this]() {
			for(auto it = boards.begin(); it != boards.end(); ++it) {
				// Update board position
				(*it)->Update();

				// Reset captured keyboard input for boards
				(*it)->direction = Board::Direction::kStay;
			}
		}
	);

	// Wait till execution of task has finished
	ftr.get();

	// Update position of ball
	ball.MoveBall(boards);
}