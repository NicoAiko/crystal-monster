//
// Created by Nico Linnemann on 19.11.19.
//

#ifndef CRYSTAL_MONSTERS_ANIMATEDSPRITE_H
#define CRYSTAL_MONSTERS_ANIMATEDSPRITE_H

#include <map>
#include <string>
#include <vector>
#include "sprite.h"
#include "globals.h"

class Graphics;

/**
 * Holds logic for animating sprites
 */

class AnimatedSprite : public Sprite {
public:
    AnimatedSprite();
    AnimatedSprite(Graphics &graphics, const std::string &filePath, Point source, Size size, FloatPoint position,
            float timeToUpdate);

    /**
     * Plays the animation provided if it's not already playing
     * @param animation
     * @param once
     */
    void playAnimation(std::string animation, bool once = false);

    /**
     * Updates the animated sprite (timer)
     * @param elapsedTime
     */
    void update(int elapsedTime);

    /**
     * Draws the sprite to the screen
     * @param graphics
     * @param position
     */
    void draw(Graphics &graphics, Point position);

    /**
     * @TODO This function has to move to the character class eventually
     * A required function that sets up all animations for a sprite
     */
    virtual void setupAnimations();

protected:
    double timeToUpdate;
    bool currentAnimationOnce;
    std::string currentAnimation;

    /**
     * Adds an animation to the map of animations for the sprite
     * @param frames
     * @param position
     * @param name
     * @param size
     * @param offset
     */
    void addAnimation(int frames, Point position, std::string name, Size size, Vector2 offset);

    /**
     * Resets all animations associated with this sprite
     */
    void resetAnimations();

    /**
     * Stops the current animation
     */
    void stopAnimation();

    /**
     * Changes the visibility of the animated sprite
     * @param visible
     */
    void setVisible(bool visible);

    /**
     * Logic that happens when an animation ends
     * @param currentAnimation
     */
    virtual void animationDone(std::string currentAnimation);

private:
    std::map<std::string, std::vector<SDL_Rect>> animations;
    std::map<std::string, Vector2> offsets;

    int frameIndex;
    double timeElapsed;
    bool visible;
};

#endif //CRYSTAL_MONSTERS_ANIMATEDSPRITE_H
