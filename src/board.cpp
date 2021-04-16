#include "board.h"
#include <cmath>
#include <iostream>

// Constructor
Board::Board(int grid_width, int grid_height, int board_length) : grid_width(grid_width), grid_height(grid_height) {
	SDL_Point board_point;
	for (int i = 0; i < board_length; i++) {
		board_point.x = static_cast<int>(1);
		board_point.y = static_cast<int>(grid_height/2 - board_length/2 + i);
		body.push_front(board_point);
	}
};

//Update Board
void Board::Update() {
	if(this->direction == Direction::kDown) {
		// Fetch highst point of board
		SDL_Point end_down = this->body.front();

		// Check if board at bottom of screen
		if(end_down.y != grid_height-1) {
			// Create new point based on oldest highest point
			SDL_Point new_end_down = end_down;
			new_end_down.y += 1;

			// Add point to the board
			this->body.push_front(new_end_down);
			this->body.pop_back();
		} 
	}
	else if (this->direction == Direction::kUp) {
		// Fetch lowest point of board
		SDL_Point end_up = this->body.back();

		// Check if board at bottom of screen
		if(end_up.y != 0) {
			// Create new point based on oldest lowest point
			SDL_Point new_end_up = end_up;
			new_end_up.y -= 1;

			// Add point to the board
			this->body.push_back(new_end_up);
			this->body.pop_front();
		}
	}
}