//
// Created by Nico Linnemann on 18.11.19.
//

#ifndef CRYSTAL_MONSTERS_CHARACTER_H
#define CRYSTAL_MONSTERS_CHARACTER_H

#include "animatedSprite.h"

class Character {
public:
    Character();
    Character(AnimatedSprite &sprite);
    virtual ~Character();

    AnimatedSprite* getSprite() const;

private:
    AnimatedSprite *sprite{};
};

#endif //CRYSTAL_MONSTERS_CHARACTER_H
