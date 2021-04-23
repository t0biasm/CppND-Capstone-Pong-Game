#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "board.h"
#include <vector>
#include <memory>

class Controller {
    public:
        void HandleInput(bool &running,  std::vector<std::unique_ptr<Board>> &boards) const;
};

#endif