// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Hit.hpp"

Hit::Hit() : Sprite() {}
Hit::Hit(short x, short y, SDL_Renderer* renderer) : Sprite(x, y, 0, 0) {
    this->renderer = renderer;
    init();
    load();
} 

void Hit::draw() {
    animation.currentFrame = ((SDL_GetTicks() - animation.startTime) 
        * animation.frameSpeedRate / 1000) % animation.numFrames;
    
    SDL_Rect origin = { animation.currentFrame * size.w, 0, size.w, size.h };
    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = size.w;
    rect.h = size.h;

    SDL_RenderCopy(renderer, sprite, &origin, &rect);
}

void Hit::move(float deltaTime) {
}

bool Hit::isExpired() {
    return (SDL_GetTicks() - startTime) > duration;
}

void Hit::init() {
    startTime = SDL_GetTicks();
    animation = AnimationComponent(2, 4, true);
}

void Hit::load() {
    SDL_Surface* idleSurface = IMG_Load("data/explosionbullet.png");
    setTexture(SDL_CreateTextureFromSurface(renderer, idleSurface));
}

int Hit::getDuration() const { return duration; }
void Hit::setDuration(int d) { duration = d; }
