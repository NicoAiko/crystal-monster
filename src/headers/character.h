//
// Created by Nico Linnemann on 18.11.19.
//

#ifndef CRYSTAL_MONSTERS_CHARACTER_H
#define CRYSTAL_MONSTERS_CHARACTER_H

#include "sprite.h"

class Character {
public:
    Character();
    Character(Sprite &sprite);
    virtual ~Character();

    Sprite* getSprite() const;
private:
    Sprite *sprite{};
};

#endif //CRYSTAL_MONSTERS_CHARACTER_H
