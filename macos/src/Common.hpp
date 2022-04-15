// 
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include <math.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfxPrimitives.h>

class Common final {
    public:
        inline static const char TITLE[] = "BHGJ";
        
        static const int FPS = 144;
        static const int MILLISECS_PER_FRAME = 1000 / FPS;
        static const int WIDTH = 640;
        static const int H_WIDTH = WIDTH / 2;

        static const int HEIGHT = 480;
        static const int H_HEIGHT = HEIGHT / 2;
};