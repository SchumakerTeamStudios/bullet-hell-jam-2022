// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"

struct ProjectileEmitterComponent {
    float speed = 0.0f;
    short dx = 0; 
    short dy = 0;
    int angle = 0; 
    int repeatFrequency;
    int lastEmissionTime;

    ProjectileEmitterComponent() {}
    ProjectileEmitterComponent(short dx, short dy) {
        this->dx = dx;
        this->dy = dy;
        this->lastEmissionTime = SDL_GetTicks();
    }
};