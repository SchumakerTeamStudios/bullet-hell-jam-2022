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

    public:
        Bullet(){}
        ~Bullet(){}
        
        void draw() override;
};