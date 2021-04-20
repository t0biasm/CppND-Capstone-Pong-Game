#ifndef BALL_H
#define BALL_H

#include <random>
#include <vector>
#include "SDL.h"
#include "board.h"

class Ball {
    public:
        enum class Heading { southEast, northEast, northWest, southWest};

        // Constructor
        Ball(int grid_width, int grid_height);

        // Function to update the ball
        void MoveBall(std::vector<Board> *boards);

        // Public variables:
        // Current position of the ball
		SDL_Point pos;

    private:
        // Function to check whether the ball hits the board
        bool IsBoardHitted(std::vector<Board> boards);
        bool IsBallOnGrid();

        // Private variables:
        // Current direction the ball moves
        Heading heading; //1: SE, 2: NE, 3: NW, 4: SW
        // To slow down the ball movement
        int counter = 0;
        int grid_width;
  		int grid_height;	
};

#endif