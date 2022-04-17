// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"
#include "Sprite.hpp"
#include "AnimationComponent.hpp"

class Player final : public Sprite {
    
    private:
        SDL_Renderer* renderer;
        
        AnimationComponent idleAnimation;
        AnimationComponent moveLeftAnimation;
        AnimationComponent moveRightAnimation;
        AnimationComponent shootLeftAnimation;
        AnimationComponent shootRightAnimation;
        AnimationComponent shootUpAnimation;
        AnimationComponent* currentAnimation;

        SDL_Texture* idleTexture;
        SDL_Texture* moveLeftTexture;
        SDL_Texture* moveRightTexture;
        SDL_Texture* shootLeftTexture;
        SDL_Texture* shootRightTexture;
        SDL_Texture* shootUpTexture;

    public:
        Player();
        Player(int x, int y, int w, int h, SDL_Renderer* renderer);
        Player(Vector2d position, Dimension size, SDL_Renderer* renderer);
        
        void move(int dx, int dy);
        void draw() override;
        void init();
        void load();
};