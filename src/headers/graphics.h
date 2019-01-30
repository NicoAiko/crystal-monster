#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
  public:
    Graphics();
    ~Graphics();
  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif
