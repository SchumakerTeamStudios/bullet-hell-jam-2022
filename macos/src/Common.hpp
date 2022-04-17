// 
// Bullet Hell Jam 2022
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
#include <SDL2/SDL2_gfxPrimitives.h>

#include "Dimension.hpp"
#include "Vector2d.hpp"

class Common final {
    
    public:
        inline static const char TITLE[] = "- SchumakerTeam -";
        
        static const unsigned short FPS = 60;
        static const unsigned short MILLISECS_PER_FRAME = 1000 / FPS;
        static const unsigned short WIDTH = 800;
        static const unsigned short H_WIDTH = WIDTH / 2;
        static const unsigned short HEIGHT = 600;
        static const unsigned short H_HEIGHT = HEIGHT / 2;
};