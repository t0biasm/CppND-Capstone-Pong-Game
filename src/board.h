#ifndef BOARD_H
#define BOARD_H

#include <deque>
#include <iostream>
#include "SDL.h"

class Board {
	public:
		enum class Direction { kUp, kDown, kStay };
		enum class State { victory, loss, ongoing };

		// Constructor
		Board(int grid_width, int grid_height, int board_length, bool opponent);

		// Destructor
		~Board() {
			//std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
		};

		// Copy Constructor
		Board(const Board &board);

		// Copy Assignment Constructor
		Board &operator=(const Board &board);

		// Move Constructor
		Board(Board &&board);

		// Move Assignment Constructor
		Board &operator=(Board &&board);

		void Update();

		State state = State::ongoing;
		Direction direction = Direction::kStay;

		float speed{0.1f};
		// first SDL_Point of vector represents upper point and last one represents lowest point
		std::deque<SDL_Point> body;

	private:
		int grid_width;
  		int grid_height;
};

#endif