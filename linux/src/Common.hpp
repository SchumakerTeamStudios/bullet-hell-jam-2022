// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <string>
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
        inline static const char TITLE[] = "- SchumakerTeam Cannon Maze BHJ 22 -";
        
        constexpr static float FPS = 60.0f;
        constexpr static float MILLISECS_PER_FRAME = 1000.0f / FPS;
        static const unsigned short WIDTH = 800;
        static const unsigned short H_WIDTH = WIDTH / 2;
        static const unsigned short HEIGHT = 600;
        static const unsigned short H_HEIGHT = HEIGHT / 2;
        constexpr static float PI = 3.1415f;
};