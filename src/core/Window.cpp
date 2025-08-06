#include "Window.h"
#include "graphics/Sprite.h"

Window::Window(const std::string &name, const int width, const int height)
    : name{name}, width{width}, height{height} {
  try {
    initialize_video();
    initialize_image();
    window.reset(create_window());
    renderer.reset(SDL_CreateRenderer(window.get(), -1,
                                      SDL_RENDERER_ACCELERATED |
                                          SDL_RENDERER_PRESENTVSYNC));
  } catch (const std::exception &ex) {
    std::string msg = "Some error occoured during game initialization.";
    std::cout << msg << std::endl;
    std::cerr << "Init error: " << ex.what() << std::endl;
    throw;
  }
}

void Window::queue_draw(const Sprite *sprite) { draw_queue.push_back(sprite); }

void Window::begin_frame() {
  SDL_Renderer *renderer = get_renderer();
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
}

void Window::close() {
  renderer.reset();
  window.reset();

  IMG_Quit();
  SDL_Quit();
}

SDL_Window *Window::create_window() {
  std::ostringstream oss;
  SDL_Window *window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED, width, height,
                                        SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    oss << "Window could not be created! SDL_Error: " << SDL_GetError();
    std::string msg = oss.str();
    std::cout << msg << std::endl;
    throw std::runtime_error(msg);
  }
  return window;
}

void Window::draw() {
  SDL_Renderer *renderer = get_renderer();
  for (auto s : draw_queue) {
    SDL_RenderCopy(renderer, s->get_texture(), NULL, s->get_rectangle());
  }
  draw_queue.clear();
}

void Window::end_frame() {
  SDL_Renderer *renderer = get_renderer();
  SDL_RenderPresent(renderer);
}

int Window::get_height() const { return height; }

std::string Window::get_name() const { return name; }

SDL_Renderer *Window::get_renderer() const { return renderer.get(); }

int Window::get_width() const { return width; }

SDL_Window *Window::get_window() const { return window.get(); }

// maybe this could be an interface drawable or something in the future
void Window::initialize_image() {
  if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) == 0) {
    std::ostringstream oss;
    oss << std::string("IMG_Init PNG failed: ") + IMG_GetError();
    std::string msg = oss.str();
    std::cout << msg << std::endl;
    throw std::runtime_error(msg);
  }
}
// maybe this could be segregated into a interface viewable or somethind
void Window::initialize_video() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::ostringstream oss;
    oss << "SDL could not initialize! SDL_Error: " << SDL_GetError();
    std::string msg = oss.str();
    std::cout << msg << std::endl;
    throw std::runtime_error(msg);
  }
}