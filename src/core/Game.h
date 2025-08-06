#ifndef EG_GAME_H
#define EG_GAME_H
#include "Window.h"
#include "graphics/Sprite.h" // how to manage this to avoid relative paths?
#include <SDL.h>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

class Game {
public:
  Game(const std::string &name, const int width, const int height);
  void close();
  void start();
  ~Game();

protected:
  // by default we are assuming a single window for the game but could be more
  // than one
  std::unique_ptr<Window> window = nullptr;
};
#endif
