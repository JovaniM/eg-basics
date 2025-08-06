#include "Sprite.h"
#include "core/Window.h"

Sprite::Sprite(Window *window, int width, int height, const std::string &src)
    : width{width}, height{height}, src{src} {
  if (src.empty()) {
    std::ostringstream oss;
    oss << "Error calling the src file at: " << src;
    std::string msg = oss.str();
    std::cout << msg << std::endl;
    throw std::runtime_error(msg);
  }
  rectangle = SDL_Rect{0, 0, width, height};
  texture.reset(IMG_LoadTexture(window->get_renderer(), src.c_str()));
  if (texture == nullptr) {
    std::ostringstream oss;
    oss << "Error reading sprite at: " << src << " - " << IMG_GetError();
    std::string msg = oss.str();
    std::cout << msg << std::endl;
    throw std::runtime_error(msg);
  }
}

SDL_Texture *Sprite::get_texture() const { return texture.get(); }
const SDL_Rect *Sprite::get_rectangle() const { return &rectangle; }

void Sprite::move(int x, int y) {
  rectangle.x += x;
  rectangle.y += y;
}