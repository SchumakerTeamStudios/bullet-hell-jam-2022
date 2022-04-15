// 
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Splash final {
    
    private:
        SDL_Renderer* renderer;
        SDL_Texture* logoTexture; 
        
        void load();  
        void loop();
        void render();
        void input();
        void unload();  
    
    public:
        Splash(SDL_Renderer *renderer);
        ~Splash();
};