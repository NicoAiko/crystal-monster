#include "input.h"

/**
 * Input class
 * Keeps track of keyboard state
 */

// This function gets called at the beginning of each new frame
// to reset the keys that are no longer relevant
void Input::beginNewFrame() {
    this->releasedKeys.clear();
    this->pressedKeys.clear();
}

// This gets called, when a key has been pressed
void Input::keyDownEvent(const SDL_Event &event) {
    this->pressedKeys[event.key.keysym.scancode] = true;
    this->heldKeys[event.key.keysym.scancode] = true;
}

// This gets called when a key is released
void Input::keyUpEvent(const SDL_Event &event) {
    this->releasedKeys[event.key.keysym.scancode] = true;
    this->heldKeys[event.key.keysym.scancode] = false;
}

bool Input::wasKeyPressed(SDL_Scancode key) {
    return this->pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key) {
    return this->releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key) {
    return this->heldKeys[key];
}
