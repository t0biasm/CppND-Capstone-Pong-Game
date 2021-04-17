#ifndef BOARD_H
#define BOARD_H

#include <deque>
#include "SDL.h"

class Board {
	public:
		enum class Direction { kUp, kDown, kStay };
		enum class State { victory, loss, ongoing };

		// Constructor
		Board(int grid_width, int grid_height, int board_length);

		void Update();

		State state = State::ongoing;
		Direction direction;

		float speed{0.1f};
		// first SDL_Point of vector represents upper point and last one represents lowest point
		std::deque<SDL_Point> body;

	private:
		int grid_width;
  		int grid_height;
};

#endif