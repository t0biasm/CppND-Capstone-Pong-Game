#include "game.h"
#include "ball.h"
#include "SDL.h"

Ball::Ball(int grid_width, int grid_height) : pos({static_cast<int>(grid_width/2), static_cast<int>(grid_height/2)}) {}

// void Ball::MoveBall() {
//     int x, y;
//     while (true) {
//         x = random_w(engine);
//         y = random_h(engine);
//     }
// }
