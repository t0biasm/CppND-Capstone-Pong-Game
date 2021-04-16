#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "board.h"
#include "ball.h"

class Game {
	public:
		Game(std::size_t grid_width, std::size_t grid_height);
		void Run(Controller const &controller, Renderer &renderer,
				std::size_t target_frame_duration);

	private:
		Board board;
		Ball ball;

		void Update();
};

#endif