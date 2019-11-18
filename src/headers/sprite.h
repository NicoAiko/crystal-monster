#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <string>
#include "Point.h"
#include "Size.h"
#include "graphics.h"

/**
 * Holds all information for individual sprites
 */

class Sprite {
  public:
    Sprite();
    Sprite(Graphics &graphics, const std::string &filePath, Point source, Size size, FloatPoint position);
    virtual ~Sprite();
    virtual void update();
    void draw(Graphics &graphics, Point point);
  private:
    SDL_Rect sourceRect{};
    SDL_Texture *spriteSheet{};

    FloatPoint position{};
};

#endif
