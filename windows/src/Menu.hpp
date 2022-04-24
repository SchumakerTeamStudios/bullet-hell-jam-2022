// 
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"
#include "Color.hpp"

class Menu final {

    private:
        SDL_Renderer* renderer;
        SDL_Texture* title;
        SDL_Texture* background;
        SDL_Rect rectBackground = {0, 0, 800, 600 };
        SDL_Texture* startWhiteTexture;
        SDL_Texture* startGrayTexture;

        TTF_Font* font60;
        TTF_Font* font24;
        
        bool isRunning = false;
        int millisecsPreviousFrame = 0;
        double deltaTime = 0.0;

        short speed = 8;
        const float pi = 3.141592f;
        const short offset = 30;
        
        void load();  
        void render();
        void input();
        void unload();  

    public:
        Menu(SDL_Renderer* renderer);
        ~Menu();

        int update();
};