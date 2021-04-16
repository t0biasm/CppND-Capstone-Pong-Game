#ifndef BALL_H
#define BALL_H

#include <random>
#include "SDL.h"

class Ball {
	public:	
        // Constructor
        Ball(int grid_width, int grid_height);
        //void MoveBall();
		SDL_Point pos;		
};

#endif