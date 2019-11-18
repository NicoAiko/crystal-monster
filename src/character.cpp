//
// Created by Nico Linnemann on 18.11.19.
//

#include "character.h"

Character::Character() = default;

Character::Character(Sprite &sprite) :
    sprite(&sprite)
{}

Character::~Character() = default;

Sprite* Character::getSprite() const {
    return this->sprite;
}
