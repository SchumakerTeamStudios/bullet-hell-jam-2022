// 
// SchumakerTeam
// Hudson Schumaker
//

#pragma once

class Common final {
    public:
        inline static const char TITLE[] = "Space Invaders";
        
        static const int FPS = 144;
        static const int MILLISECS_PER_FRAME = 1000 / FPS;
        static const int WIDTH = 640;
        static const int H_WIDTH = WIDTH / 2;

        static const int HEIGHT = 480;
        static const int H_HEIGHT = HEIGHT / 2;
};