#ifndef GAME_H
#define GAME_H

class Graphics;

class Game {
    public:
        Game();
        ~Game();
        void Run();
    private:
        void gameLoop();
        void draw(Graphics &graphics);
        void update(float elapsedTime);
};

#endif
