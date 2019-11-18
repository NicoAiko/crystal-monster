//
// Created by Nico Linnemann on 18.11.19.
//

#include "sprite.h"

Sprite::Sprite() = default;

Sprite::Sprite(Graphics &graphics, const std::string &filePath, Point source, Size size, FloatPoint position):
    position(position) {
    this->sourceRect.x = source.x;
    this->sourceRect.y = source.y;
    this->sourceRect.w = size.width;
    this->sourceRect.h = size.height;

    this->spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));

    if (this->spriteSheet == nullptr) {
        printf("\nError: Unable to load image\n");
    }
}

Sprite::~Sprite() = default;

void Sprite::draw(Graphics &graphics, Point point) {
    SDL_Rect destinationRectangle = { point.x, point.y, this->sourceRect.w, this->sourceRect.h };

    graphics.blitSurface(this->spriteSheet, &this->sourceRect, &destinationRectangle);
}

void Sprite::update() {}