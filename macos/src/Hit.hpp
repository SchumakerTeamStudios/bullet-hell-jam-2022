// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"
#include "Sprite.hpp"
#include "AnimationComponent.hpp"

class Hit final : public Sprite {

    private:
        SDL_Renderer* renderer;
        AnimationComponent animation;

        float speed = 0.2f;
        int duration = 2000;
        int startTime;

    public:
        Hit();
        Hit(short x, short y, SDL_Renderer* renderer);
        short dx; 
        short dy;

        void draw() override;
        void move(float deltaTime);
        bool isExpired();
        void init();
        void load();
        int getDuration() const;
        void setDuration(int d);
};