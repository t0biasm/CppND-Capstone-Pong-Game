#include <algorithm>
#include "game.h"
#include "ball.h"
#include "board.h"
#include "SDL.h"

Ball::Ball(int grid_width, int grid_height) : grid_width(grid_width), grid_height(grid_height),
    pos({static_cast<int>(grid_width/2), static_cast<int>(grid_height/2)}), 
    heading(Heading( rand() % 4) ) {}

bool Ball::IsBoardHitted(std::vector<std::unique_ptr<Board>> &boards) {
    for(auto it = boards.begin(); it != boards.end(); ++it) {
        for(auto iter = (*it)->body.begin(); iter != (*it)->body.end(); ++iter ) {
            if(iter->x == pos.x && (iter->y == pos.y || (pos.y < 0 && iter->y == 0) || (pos.y >= grid_height && iter->y == grid_height-1))) {
                return true;
            }
        }
    }
    return false;
}

bool Ball::IsBallOnGrid() {
    if(pos.x >= 0 && pos.x < grid_width && pos.y >= 0 && pos.y < grid_height) {
        return true;
    }
    else {
        return false;
    }
}

void Ball::MoveBall(std::vector<std::unique_ptr<Board>> &boards) {
    if(counter % 5 == 0) {
        if(heading == Heading::northWest) {
            pos.x -= 1;
            pos.y -= 1;
            if(IsBallOnGrid()) {
                if(IsBoardHitted(boards)){
                    pos.x += 2;
                    heading = Heading::northEast;
                }
                if(pos.x == 0) {
                    boards.at(0)->state = Board::State::loss;
                }
            } else {
                if(IsBoardHitted(boards)) {
                    pos.x += 2;
                    pos.y += 2;
                    heading = Heading::southEast;
                }
                else
                {
                    pos.y += 1;
                    heading = Heading::southWest;
                }
            }
        }
        else if(heading == Heading::southEast) {
            pos.x += 1;
            pos.y += 1;
            if(IsBallOnGrid()) {
                if(IsBoardHitted(boards)){
                    pos.x -= 2;
                    heading = Heading::southWest;
                }
                if(pos.x == grid_width-1) {
                    boards.at(0)->state = Board::State::loss;
                }
            } else {
                if(IsBoardHitted(boards)) {
                    pos.x -= 2;
                    pos.y -= 2;
                    heading = Heading::northWest;
                }
                else {
                    pos.y -= 2;
                    heading = Heading::northEast;
                }
            }
        }
        else if(heading == Heading::northEast) {
            pos.x += 1;
            pos.y -= 1;
            if(IsBallOnGrid()) {
                if(IsBoardHitted(boards)){
                    pos.x -= 2;
                    heading = Heading::northWest;
                }
                if(pos.x == grid_width-1) {
                    boards.at(0)->state = Board::State::loss;
                }
            } else {
                if(IsBoardHitted(boards)) {
                    pos.x -= 2;
                    pos.y += 2;
                    heading = Heading::southWest;
                }
                else {
                    pos.y += 2;
                    heading = Heading::southEast;
                }
            }
        }
        else {
            pos.x -= 1;
            pos.y += 1;
            if(IsBallOnGrid()) {
                if(IsBoardHitted(boards)){
                    pos.x += 2;
                    heading = Heading::southEast;
                }
                if(pos.x == 0) {
                    boards.at(0)->state = Board::State::loss;
                }
            } else {
                if(IsBoardHitted(boards)) {
                    pos.x += 2;
                    pos.y -= 2;
                    heading = Heading::northEast;
                }
                else {
                    pos.y -= 2;
                    heading = Heading::northWest;
                }
            }
        }
    }
    ++counter;
}
