#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "board.h"

void Controller::HandleInput(bool &running, std::vector<std::unique_ptr<Board>> &boards) const {  
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			running = false;
		} 
	}

	const Uint8* keystate = SDL_GetKeyboardState(NULL);
    //continuous-response keys
    if (keystate[SDL_SCANCODE_W]) boards.front()->direction = Board::Direction::kUp;
    if (keystate[SDL_SCANCODE_S]) boards.front()->direction = Board::Direction::kDown;
    if (keystate[SDL_SCANCODE_UP]) boards.back()->direction = Board::Direction::kUp;
    if (keystate[SDL_SCANCODE_DOWN]) boards.back()->direction = Board::Direction::kDown;
}