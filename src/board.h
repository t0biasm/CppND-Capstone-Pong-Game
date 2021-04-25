#ifndef BOARD_H
#define BOARD_H

#include <deque>
#include <iostream>
#include "SDL.h"

class Board {
	public:
		enum class Direction { kUp, kDown, kStay };
		enum class State { victory, loss, ongoing };

		// Basic Constructor
		Board(int grid_width, int grid_height, int board_length, bool opponent);
		
		// Rule of Five
		Board(const Board &board);
		Board &operator=(const Board &board);
		Board(Board &&board);
		Board &operator=(Board &&board);
		~Board() {
			//std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
		};

		// Member function to update board position
		void Update();

		// Current game state of board
		State state = State::ongoing;
		// Current direction the board is heading to
		Direction direction = Direction::kStay;

		float speed{0.1f};
		// first SDL_Point of vector represents upper point and last one represents lowest point
		std::deque<SDL_Point> body;

	private:
		int grid_width;
  		int grid_height;
};

#endif