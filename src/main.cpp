#include "core/Game.h"
#include <SDL.h>
#include <iostream>
#include <memory>
// Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main() {
  std::unique_ptr<Game> game =
      std::make_unique<Game>("SDL Tutorial", SCREEN_WIDTH, SCREEN_HEIGHT);
  game->start();
  return 0;
}