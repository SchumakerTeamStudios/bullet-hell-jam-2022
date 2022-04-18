// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"
#include "Sprite.hpp"

class Bullet final : public Sprite {

    private:
        SDL_Renderer* renderer;
        float speed = 1.0f;
        int duration = 7000;
        int startTime;

    public:
        Bullet();
        Bullet(short x, short y, SDL_Renderer* renderer);
        ~Bullet();

        void draw() override;
        void move(short dx, short dy, float deltaTime);
        void init();
        void load();
        float getSpeed() const;
        void setSpeed(float s);
        int getDuration() const;
        void setDuration(int d);
};