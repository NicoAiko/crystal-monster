#include <SDL2/SDL.h>

#include "graphics.h"

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(1280, 720, 0, &this->window, &this->renderer);
	SDL_SetWindowTitle(this->window, "Crystal Monsters");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
}
