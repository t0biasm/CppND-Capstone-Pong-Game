#ifndef BOARD_H
#define BOARD_H

#include <deque>
#include "SDL.h"

class Board {
	public:
		enum class Direction { kUp, kDown, kStay };
		enum class State { victory, loss, ongoing };

		// Constructor
		Board(int grid_width, int grid_height, int board_length, bool opponent);

		// // Destructor
		// ~Board();

		// Copy Constructor
		Board(const Board &board) {
			body = board.body;
			grid_width = board.grid_width;
			grid_height = board.grid_height;
		}

		// Copy Assignment Constructor
		Board &operator=(const Board &board) {
			if (this == &board) return *this;
			
			body = board.body;
			grid_width = board.grid_width;
			grid_height = board.grid_height;
			
			return *this;
		}

		// Move Constructor
		Board(Board &&board) : body(std::move(board.body)) {
			grid_width = board.grid_width;
			grid_height = board.grid_height;
			
			board.grid_width = 0;
			board.grid_height = 0;
		}

		// Move Assignment Constructor
		Board &operator=(Board &&board) {
			body = std::move(board.body);
			
			grid_width = board.grid_width;
			grid_height = board.grid_height;
			
			board.grid_width = 0;
			board.grid_height = 0;
    		
			return *this;
		}

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