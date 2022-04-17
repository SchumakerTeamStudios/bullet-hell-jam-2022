// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Canvas.hpp"

class Level1 final : public Canvas {

    private:
        SDL_Renderer* renderer;
        SDL_Texture* background;
        SDL_Rect rectBackground = {0, 0, 800, 600 };
        bool isRunning = false;

        void input() override; 
        void update() override;
        void collision() override;
        void render() override;
        void load() override;
        void unload() override;

    public:
        Level1(SDL_Renderer* renderer);
        ~Level1();

        bool loop() override;
};