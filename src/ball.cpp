#include <algorithm>
#include "game.h"
#include "ball.h"
#include "SDL.h"

Ball::Ball(int grid_width, int grid_height) : grid_width(grid_width), grid_height(grid_height),
    pos({static_cast<int>(grid_width/2), static_cast<int>(grid_height/2)}), 
    heading(Heading::northWest) {}

bool Ball::IsBoardHitted(Board *board) {
    for( auto iter = board->body.begin(); iter != board->body.end(); ++iter ) {
        if(iter->x == pos.x && iter->y == pos.y) {
            return true;
        }
    }
    return false;
}

void Ball::MoveBall(Board *board) {
    if(counter % 5 == 0) {
        if(heading == Heading::northWest) {
            if(pos.x - 1 > 1) {
                pos.x -= 1;
            } else {
                pos.x -= 1;
                if(IsBoardHitted(board)) {
                    pos.x += 2;
                    heading = Heading::northEast;
                } 
                else {
                    board->state = Board::State::loss;
                }
                // heading = Heading::northEast;
            }

            if(pos.y - 1 >= 0) {
                pos.y -= 1;
            } else {
                pos.y += 1;
                heading = Heading::southWest;
            }
        }
        else if(heading == Heading::southEast) {
            if(pos.x + 1 < grid_width) {
                pos.x += 1;
            } else {
                pos.x -= 1;
                heading = Heading::southWest;
            }

            if(pos.y + 1 < grid_height) {
                pos.y += 1;
            } else {
                pos.y -= 1;
                heading = Heading::northEast;
            }
        }
        else if(heading == Heading::northEast) {
            if(pos.x + 1 < grid_width) {
                pos.x += 1;
            } else {
                pos.x -= 1;
                heading = Heading::northWest;
            }

            if(pos.y - 1 >= 0) {
                pos.y -= 1;
            } else {
                pos.y += 1;
                heading = Heading::southEast;
            }
        }
        else {
            if(pos.x - 1 > 1) {
                pos.x -= 1;
            } else {
                pos.x -= 1;
                if(IsBoardHitted(board)) {
                    pos.x += 2;
                    heading = Heading::southEast;
                } 
                else {
                    board->state = Board::State::loss;
                }
                //heading = Heading::southEast;
            }

            if(pos.y + 1 < grid_height) {
                pos.y += 1;
            } else {
                pos.y -= 1;
                heading = Heading::northWest;
            }
        }
    }
    ++counter;
}
