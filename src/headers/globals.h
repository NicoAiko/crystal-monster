//
// Created by Nico Linnemann on 19.11.19.
//

#ifndef CRYSTAL_MONSTERS_GLOBALS_H
#define CRYSTAL_MONSTERS_GLOBALS_H

namespace globals {
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    const float SPRITE_SCALE = 2.0f;
}

struct Vector2 {
    int x, y;

    Vector2() :
        x(0), y(0)
    {}

    Vector2(int x, int y) :
        x(x), y(y)
    {}

    Vector2 zero() {
        return Vector2(0, 0);
    }
};

#endif //CRYSTAL_MONSTERS_GLOBALS_H
