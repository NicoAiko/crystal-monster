//
// Created by Nico Linnemann on 18.11.19.
//

#include "character.h"

Character::Character() = default;

Character::Character(AnimatedSprite &sprite) :
    sprite(&sprite)
{}

Character::~Character() = default;

AnimatedSprite* Character::getSprite() const {
    return this->sprite;
}
