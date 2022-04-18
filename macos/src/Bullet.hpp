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

    public:
        Bullet(){}
        ~Bullet(){}
        void draw() override;
};