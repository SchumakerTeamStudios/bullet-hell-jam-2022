// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"
#include "Sprite.hpp"
#include "AnimationComponent.hpp"

class Bullet final : public Sprite {

    private:
        SDL_Renderer* renderer;
        AnimationComponent animation;

        float speed = 0.2f;
        int duration = 4000;
        int startTime;
        
    public:
        Bullet();
        Bullet(short x, short y, SDL_Renderer* renderer);
        short dx; 
        short dy;
        bool destroyed = false; 

        void draw() override;
        void move(float deltaTime);
        bool isExpired();
        void init();
        float getSpeed() const;
        void setSpeed(float s);
        int getDuration() const;
        void setDuration(int d);
};