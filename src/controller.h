#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "board.h"

class Controller {
    public:
        void HandleInput(bool &running, Board &board) const;
};

#endif