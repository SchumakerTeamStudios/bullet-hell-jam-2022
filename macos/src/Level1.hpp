// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Bullet.hpp"
#include "Canvas.hpp"
#include "Enemy.hpp"
#include "Hit.hpp"
#include "Player.hpp"

class Level1 final : public Canvas {

    private:
        SDL_Renderer* renderer;
        SDL_Texture* background;
        SDL_Rect rectBackground = { 0, 0, 800, 600 };
        Player player;
        Mix_Chunk* explodeSfx;

        bool isRunning = false;
        Uint64 currentTick = 0;
        Uint64 lastTick = 0;
        float deltaTime = 0.0f;
        
        std::vector<Enemy> enemies;
        std::vector<Bullet> bullets;
        std::vector<Bullet> enemiesBullets;
        std::vector<Hit> hits;

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