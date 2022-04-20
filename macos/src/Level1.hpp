// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Canvas.hpp"
#include "Bullet.hpp"
#include "Player.hpp"

class Level1 final : public Canvas {

    private:
        SDL_Renderer* renderer;
        SDL_Texture* background;
        SDL_Rect rectBackground = { 0, 0, 800, 600 };
        Player player;

        bool isRunning = false;
        Uint64 currentTick = 0;
        Uint64 lastTick = 0;
        float deltaTime = 0.0f;
        std::vector<Bullet> bullets;

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