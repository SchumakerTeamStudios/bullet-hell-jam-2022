// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Level1.hpp"

Level1::Level1(SDL_Renderer* renderer) {
    this->renderer = renderer;
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
            case SDL_QUIT: {
                isRunning = false;
            } break;
            

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


    SDL_RenderPresent(renderer);     
}

void Level1::load() {
    SDL_Surface* backgroundSurface = IMG_Load("data/back800a.png");
    background = SDL_CreateTextureFromSurface(renderer, backgroundSurface);   
}

void Level1::unload() {
    SDL_DestroyTexture(background);
}
