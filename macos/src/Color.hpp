// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"

class Color final {
    
    public:
        Color();
        ~Color();

        static SDL_Color getRed();
        static SDL_Color getGreen();
        static SDL_Color getBlue();
        static SDL_Color getWhite();
        static SDL_Color getBlack();
        static SDL_Color getGray();
        static SDL_Color getOrange();
        static SDL_Color getYellow();
        static SDL_Color getPink();
};