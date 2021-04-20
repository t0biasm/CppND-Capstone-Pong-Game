#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "board.h"
#include <vector>

class Controller {
    public:
        void HandleInput(bool &running,  std::vector<Board> &boards) const;
};

#endif