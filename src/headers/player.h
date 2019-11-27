//
// Created by Nico Linnemann on 26.11.19.
//

#ifndef CRYSTAL_MONSTERS_PLAYER_H
#define CRYSTAL_MONSTERS_PLAYER_H

#include "character.h"
#include "graphics.h"
#include "Point.h"

class Player : public Character {
public:
    Player();
    Player(Graphics &graphics, Point position);
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    virtual void animationDone(std::string currentAnimation);
    virtual void setupAnimations();
private:
};

#endif //CRYSTAL_MONSTERS_PLAYER_H
