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
		// else if (e.type == SDL_KEYDOWN) {
		// 	if (e.key.keysym.sym==SDLK_w) boards.front().direction = Board::Direction::kUp;
		// 	if (e.key.keysym.sym==SDLK_s) boards.front().direction = Board::Direction::kDown;
		// 	if (e.key.keysym.sym==SDLK_UP) boards.back().direction = Board::Direction::kUp;
		// 	if (e.key.keysym.sym==SDLK_DOWN) boards.back().direction = Board::Direction::kDown;
		// 	break;
		// }
	}

	const Uint8* keystate = SDL_GetKeyboardState(NULL);
    //continuous-response keys
    if (keystate[SDL_SCANCODE_W]) boards.front().direction = Board::Direction::kUp;
    if (keystate[SDL_SCANCODE_S]) boards.front().direction = Board::Direction::kDown;
    if (keystate[SDL_SCANCODE_UP]) boards.back().direction = Board::Direction::kUp;
    if (keystate[SDL_SCANCODE_DOWN]) boards.back().direction = Board::Direction::kDown;
}