#include <SDL2/SDL.h>

#include "game.h"
#include "graphics.h"
#include "input.h"
/**
 * Game class
 * Holds game loop logic
 */

namespace {
    const int FPS = 50;
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
};

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
}

Game::~Game() {
    IMG_Quit();
    SDL_Quit();
}

void Game::Run() {
    this->gameLoop();
}

void Game::gameLoop() {
    Graphics graphics;
    Input input;
    SDL_Event event;

    AnimatedSprite sprite = AnimatedSprite(graphics, "assets/crystals/yellow.png", { 0, 0 }, { 128, 128 }, { 100, 100 }, 100);
    this->player = Character(sprite);
    this->player.getSprite()->setupAnimations();
    this->player.getSprite()->playAnimation("Run");

    int LAST_UPDATE_TIME = SDL_GetTicks();
    // Start Game Loop
    while(true) {
        input.beginNewFrame();

        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                // Makes sure, you're not holding down a key
                if (event.key.repeat == 0) {
                    input.keyDownEvent(event);
                }
            }
            else if (event.type == SDL_KEYUP) {
                input.keyUpEvent(event);
            }
            else if (event.type == SDL_QUIT) {
                IMG_Quit();
                SDL_Quit();
                return;
            }
        }

        if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) {
            return;
        }

        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));

        LAST_UPDATE_TIME = CURRENT_TIME_MS;

        this->draw(graphics);
    }
}

void Game::update(float elapsedTime) {
    this->player.getSprite()->update(elapsedTime);
}

void Game::draw(Graphics &graphics) {
    graphics.clear();

    this->player.getSprite()->draw(graphics, { 100, 100 });

    graphics.flip();
}


