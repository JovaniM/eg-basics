#include "Game.h"

Game::Game(const std::string &name, const int width, const int height)
    : window{std::make_unique<Window>(name, width, height)} {}

void Game::close() { window->close(); }

void Game::start() {
  SDL_Event e;
  bool quit = false;
  // We need an asset manager instead put this here
  // how to manage this to avoid relative paths?
  std::unique_ptr<Sprite> sprite = std::make_unique<Sprite>(
      window.get(), 70, 100, "assets/characters/monster.png");
  while (quit == false) {
    // I dont like big functions should be better to add handlers?
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }
      if (e.type == SDL_KEYDOWN) { // I dont like big functions should be better
                                   // to add handlers?
        switch (e.key.keysym.sym) {
        case SDLK_ESCAPE:
          quit = true;
          break;
        case SDLK_DOWN:
          sprite.get()->move(0, 5);
          break;
        case SDLK_UP:
          sprite.get()->move(0, -5);
          break;
        case SDLK_LEFT:
          sprite.get()->move(-5, 0);
          break;
        case SDLK_RIGHT:
          sprite.get()->move(5, 0);
          break;

        default:
          break;
        }
      }
    }
    window->begin_frame();
    window->queue_draw(sprite.get());

    window->draw();
    window->end_frame();
  }
}

Game::~Game() { close(); }