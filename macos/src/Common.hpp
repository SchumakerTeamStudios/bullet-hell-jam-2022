// 
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "Dimension.hpp"
#include "Vector2d.hpp"

class Common final {
    public:
        inline static const char TITLE[] = "- SchumakerTeam -";
        
        static const unsigned short int FPS = 60;
        static const unsigned short int MILLISECS_PER_FRAME = 1000 / FPS;
        static const unsigned short int WIDTH = 800;
        static const unsigned short int H_WIDTH = WIDTH / 2;
        static const unsigned short int HEIGHT = 600;
        static const unsigned short int H_HEIGHT = HEIGHT / 2;
};