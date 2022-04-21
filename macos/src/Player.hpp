// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"
#include "Bullet.hpp"
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
        SDL_Texture* bulletTexture;
        SDL_Texture* bulletLeftTexture;
        SDL_Texture* bulletRightTexture;

    public:
        Player();
        Player(short x, short y, short w, short h, SDL_Renderer* renderer);
        Player(Vector2d position, Dimension size, SDL_Renderer* renderer);
        
        void move(short dx, short dy, float deltaTime);
        void update(float deltaTime);
        void draw() override;
        Bullet fire();
        Bullet fireLeft();
        Bullet fireRight();
        void init();
        void load();
        void unload();
};