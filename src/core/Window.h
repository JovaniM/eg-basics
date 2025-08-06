#ifndef EG_WINDOW_H
#define EG_WINDOW_H
#include <SDL.h>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

class Sprite;

struct SDL_WindowDeleter {
  void operator()(SDL_Window *win) const {
    if (win)
      SDL_DestroyWindow(win);
  }
};

struct SDL_RendererDeleter {
  void operator()(SDL_Renderer *render) const {
    if (render)
      SDL_DestroyRenderer(render);
  }
};

using WindowPtr = std::unique_ptr<SDL_Window, SDL_WindowDeleter>;
using RendererPtr = std::unique_ptr<SDL_Renderer, SDL_RendererDeleter>;
class Window {
public:
  Window(const std::string &name, const int width, const int height);
  void queue_draw(const Sprite *sprite);
  void begin_frame();
  void close();
  void draw();
  void end_frame();
  int get_height() const;
  std::string get_name() const;
  SDL_Renderer *get_renderer() const;
  int get_width() const;
  SDL_Window *get_window() const;

protected:
  const std::string name;
  int width;
  int height;
  std::vector<const Sprite *> draw_queue;

private:
  RendererPtr renderer = nullptr;
  WindowPtr window = nullptr;
  SDL_Window *create_window();
  void initialize_image();
  void initialize_video();
};
#endif