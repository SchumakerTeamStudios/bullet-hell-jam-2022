// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"

struct AnimationComponent {
    short numFrames;
    short currentFrame;
    short frameSpeedRate;
    bool isLoop;
    int startTime;

    AnimationComponent(short numFrames = 1, short frameSpeedRate = 1, bool isLoop = true) {
        this->numFrames = numFrames;
        this->currentFrame = 1;
        this->frameSpeedRate = frameSpeedRate;
        this->isLoop = isLoop;
        this->startTime = SDL_GetTicks();
    }
};