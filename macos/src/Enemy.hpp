// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Common.hpp"
#include "Bullet.hpp"
#include "Sprite.hpp"
#include "AnimationComponent.hpp"

class Enemy final : public Sprite {
    
    private:
        SDL_Renderer* renderer;
        SDL_Texture* shootTexture;
        AnimationComponent animation;
        Mix_Chunk* shootSfx;
        bool destroyed = false;
        std::string spriteName;
        std::string shootSfxName;
        std::string shootGfxName;
    
       
    public:
        Enemy();
        Enemy(short x, short y, short w, short h, std::string sprtName, std::string ssfxName, std::string ssgfxName,
            SDL_Renderer* renderer);
        
        void move(short dx, short dy, float deltaTime);
        void update(float deltaTime);
        void draw() override;
        Bullet fire();
        void init();
        void load();
        void unload();    
        int hp;  
};