#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "board.h"

void Controller::HandleInput(bool &running, std::vector<Board> &boards) const {
  	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			running = false;
		} 
		else if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym) {
				case SDLK_w:
					boards.front().direction = Board::Direction::kUp;
					//boards.at(0) = board_left;
					break;

				case SDLK_s:
					boards.front().direction = Board::Direction::kDown;
					//boards.at(0) = board_left;
					break;

				case SDLK_UP:
					boards.back().direction = Board::Direction::kUp;
					//boards.at(1) = board_left;
					break;

				case SDLK_DOWN:
					boards.back().direction = Board::Direction::kDown;
					//boards.at(1) = board_left;
					break;
			}
		}
	}
}