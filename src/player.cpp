//
// Created by Nico Linnemann on 26.11.19.
//

#include "player.h"

Player::Player() = default;

Player::Player(Graphics &graphics, Point position)
    : AnimatedSprite(graphics, "assets/characters/player.png", { 0, 0 }, { 16, 16 }, position, 100)
{

}
