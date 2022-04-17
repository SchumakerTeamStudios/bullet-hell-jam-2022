// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"
#include "Sprite.hpp"

class Player final : public Sprite {
    
    private:
        
    public:
        Player();
        Player(int x, int y);
        Player(int x, int y, int w, int h);
        Player(Vector2d position, Dimension size);
        
        void move(int dx, int dy);
        void draw(SDL_Renderer* renderer) override;
};