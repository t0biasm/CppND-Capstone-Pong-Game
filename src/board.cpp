#include "board.h"
#include <cmath>
#include <iostream>

// Constructor
Board::Board(int grid_width, int grid_height, int board_length, bool opponent) : grid_width(grid_width), grid_height(grid_height) {
	SDL_Point board_point;
	for (int i = 0; i < board_length; i++) {
		if(opponent == false) {
			board_point.x = static_cast<int>(1);
		}
		else {
			board_point.x = static_cast<int>(grid_width-2);
		}
		board_point.y = static_cast<int>(grid_height/2 - board_length/2 + i);
		body.push_front(board_point);
	}
};

// Copy Constructor
Board::Board(const Board &board) {
	// std::cout << "COPYING content of instance " << &board << " to instance " << this << std::endl;
	body = board.body;
	grid_width = board.grid_width;
	grid_height = board.grid_height;
}

// Copy Assignment Constructor
Board &Board::operator=(const Board &board) {
	// std::cout << "ASSIGNING content of instance " << &board << " to instance " << this << std::endl;
	
	if (this == &board) return *this;
	
	body = board.body;
	grid_width = board.grid_width;
	grid_height = board.grid_height;
	
	return *this;
}

// Move Constructor
Board::Board(Board &&board) : body(std::move(board.body)) {
	// std::cout << "MOVING (c’tor) instance " << &board << " to instance " << this << std::endl;
	grid_width = board.grid_width;
	grid_height = board.grid_height;
	
	board.grid_width = 0;
	board.grid_height = 0;
}

// Move Assignment Constructor
Board &Board::operator=(Board &&board) {
	// std::cout << "MOVING (assign) instance " << &board << " to instance " << this << std::endl;

	body = std::move(board.body);
	
	grid_width = board.grid_width;
	grid_height = board.grid_height;
	
	board.grid_width = 0;
	board.grid_height = 0;
	
	return *this;
}

// Update Board
void Board::Update() {
	//std::cout << this->state << std::endl;
	if(direction == Direction::kDown) {
		// Fetch highst point of board
		SDL_Point end_down = body.front();

		// Check if board at bottom of screen
		if(end_down.y != grid_height-1) {
			// Create new point based on oldest highest point
			SDL_Point new_end_down = end_down;
			new_end_down.y += 1;

			// Add point to the board
			body.push_front(new_end_down);
			body.pop_back();
		} 
	}
	else if (direction == Direction::kUp) {
		// Fetch lowest point of board
		SDL_Point end_up = body.back();

		// Check if board at bottom of screen
		if(end_up.y != 0) {
			// Create new point based on oldest lowest point
			SDL_Point new_end_up = end_up;
			new_end_up.y -= 1;

			// Add point to the board
			body.push_back(new_end_up);
			body.pop_front();
		}
	}
}