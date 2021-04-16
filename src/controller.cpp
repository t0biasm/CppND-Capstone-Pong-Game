#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "board.h"

void Controller::HandleInput(bool &running, Board &board) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          board.direction = Board::Direction::kUp;
          break;

        case SDLK_DOWN:
          board.direction = Board::Direction::kDown;
          break;
      }
    }
  }
}