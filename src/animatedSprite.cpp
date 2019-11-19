//
// Created by Nico Linnemann on 19.11.19.
//

#include "animatedSprite.h"

AnimatedSprite::AnimatedSprite() {}

AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string &filePath, Point source, Size size,
                               FloatPoint position, float timeToUpdate) :
                               Sprite(graphics, filePath, source, size, position),
                               frameIndex(0),
                               timeToUpdate(timeToUpdate),
                               timeElapsed(0.0),
                               visible(true),
                               currentAnimationOnce(false),
                               currentAnimation("")
{}

void AnimatedSprite::addAnimation(int frames, Point position, std::string name, Size size, Vector2 offset) {
    std::vector<SDL_Rect> rectangles;

    for (int i = 0; i < frames; i++) {
        SDL_Rect newRect = { (i + position.x) * size.width, position.y, size.width, size.height };
        rectangles.push_back(newRect);
    }

    this->animations.insert(std::pair<std::string, std::vector<SDL_Rect>>(name, rectangles));
    this->offsets.insert(std::pair<std::string, Vector2>(name, offset));
}

void AnimatedSprite::resetAnimations() {
    this->animations.clear();
    this->offsets.clear();
}

void AnimatedSprite::playAnimation(std::string animation, bool once) {
    this->currentAnimationOnce = once;

    if (this->currentAnimation != animation) {
        this->currentAnimation = animation;
        this->frameIndex = 0;
    }
}

void AnimatedSprite::setVisible(bool visible) {
    this->visible = visible;
}

void AnimatedSprite::stopAnimation() {
    this->frameIndex = 0;
    this->animationDone(this->currentAnimation);
}

void AnimatedSprite::update(int elapsedTime) {
    Sprite::update();

    this->timeElapsed += elapsedTime;
    if (this->timeElapsed > this->timeToUpdate) {
        this->timeElapsed -= this->timeToUpdate;

        // If we're currently not at the last animation frame
        if (this->frameIndex < this->animations[this->currentAnimation].size() - 1) {
            this->frameIndex++;
        } else {
            if (this->currentAnimationOnce) {
                this->setVisible(false);
            }

            this->frameIndex = 0;
            this->animationDone(this->currentAnimation);
        }
    }
}

void AnimatedSprite::draw(Graphics &graphics, Point position) {
    if (this->visible) {
        SDL_Rect destinationRectangle;
        destinationRectangle.x = position.x + this->offsets[this->currentAnimation].x;
        destinationRectangle.y = position.y + this->offsets[this->currentAnimation].y;
        destinationRectangle.w = this->sourceRect.w * globals::SPRITE_SCALE;
        destinationRectangle.h = this->sourceRect.h * globals::SPRITE_SCALE;

        SDL_Rect sourceRect = this->animations[this->currentAnimation][this->frameIndex];
        graphics.blitSurface(this->spriteSheet, &sourceRect, &destinationRectangle);
    }
}

void AnimatedSprite::animationDone(std::string currentAnimation) {}

void AnimatedSprite::setupAnimations() {
    this->addAnimation(4, { 0, 0 }, "Run", { 16, 16 }, Vector2(0, 0));
}