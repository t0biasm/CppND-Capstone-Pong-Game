#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "board.h"

class Controller {
 public:
  void HandleInput(bool &running, Board &board) const;

 private:
  void ChangeDirection(Board &board, Board::Direction input,
                       Board::Direction opposite) const;
};

#endif