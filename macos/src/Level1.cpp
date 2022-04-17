// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Level1.hpp"

Level1::Level1(SDL_Renderer* renderer) {
    this->renderer = renderer;
    player = Player(368, 535, 64, 64, renderer);
    load();
}

Level1::~Level1() {
    unload();
}

bool Level1::loop() {
    isRunning = true;
    while(isRunning) {
        input(); 
        update();
        collision();
        render(); 
    }
    return true;
}

void Level1::input() {
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        switch(e.type) {
            case SDL_QUIT:
                isRunning = false;
                exit(0);
            break;
            
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_SPACE) {
                    //player.fire();
                }
                if (e.key.keysym.sym == SDLK_LEFT) {
                    player.move(-4, 0);
                }
                if (e.key.keysym.sym == SDLK_RIGHT) {
                    player.move(4, 0);
                }
                if (e.key.keysym.sym == SDLK_UP) {
                    player.move(0, -4);
                }
                if (e.key.keysym.sym == SDLK_DOWN) {
                    player.move(0, 4);
                }
            break;

            case SDL_KEYUP:
                player.move(0, 0);
            break;
        }
    }
}

void Level1::update() {
    
}

void Level1::collision() {
    
}

void Level1::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    SDL_RenderCopy(renderer, background, NULL, &rectBackground);

    player.draw();

    SDL_RenderPresent(renderer);     
}

void Level1::load() {
    SDL_Surface* backgroundSurface = IMG_Load("data/back800a.png");
    background = SDL_CreateTextureFromSurface(renderer, backgroundSurface);   
}

void Level1::unload() {
    SDL_DestroyTexture(background);
}
