#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include <unistd.h>

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{960};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{48};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  return 0;
}