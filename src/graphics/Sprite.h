#ifndef EG_SPRITE_H
#define EG_SPRITE_H
#include <SDL_image.h>
#include <cstdint>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

struct TextureDeleter {
  void operator()(SDL_Texture *t) const {
    if (t)
      SDL_DestroyTexture(t);
  }
};

class Window;

using TexturePtr = std::unique_ptr<SDL_Texture, TextureDeleter>;

class Sprite {
public:
  Sprite(Window *window, int width, int height, const std::string &src);
  const SDL_Rect *get_rectangle() const;
  SDL_Texture *get_texture() const;
  void move(int x, int y);

protected:
  int width = 0;
  int height = 0;
  std::string src = "";
  TexturePtr texture = nullptr;
  SDL_Rect rectangle{0, 0, 0, 0};
};
#endif
