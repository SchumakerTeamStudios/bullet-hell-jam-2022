// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"
#include "Sprite.hpp"

class Object final : public Sprite {
    
    private:
        SDL_Renderer* renderer;

    public:
        Object();
        Object(short x, short y, SDL_Renderer* renderer);

        void draw() override;
        void move(float deltaTime);
        void init();
        void load();
};