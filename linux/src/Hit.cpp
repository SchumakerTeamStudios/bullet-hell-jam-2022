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
    if (!destroyed) {
        animation.currentFrame = ((SDL_GetTicks() - animation.startTime) 
            * animation.frameSpeedRate / 1000) % animation.numFrames;

        SDL_Rect origin = { animation.currentFrame * 32, 0, 32, 32 };
        SDL_Rect rect;
        rect.x = position.x;
        rect.y = position.y;
        rect.w = 32;
        rect.h = 32;

        SDL_RenderCopy(renderer, sprite, &origin, &rect);

        if (!animation.isLoop && animation.currentFrame == (animation.numFrames)-1) {
            destroyed = true;
        }
    }
}

void Hit::move(float deltaTime) {
}

bool Hit::isExpired() {
    return (SDL_GetTicks() - startTime) > duration;
}

void Hit::init() {
    startTime = SDL_GetTicks();
    animation = AnimationComponent(4, 8, false);
}

void Hit::load() {
    SDL_Surface* surface = IMG_Load("data/explosionbullet.png");
    setTexture(SDL_CreateTextureFromSurface(renderer, surface)); 
    SDL_Point point;
    SDL_QueryTexture(sprite, NULL, NULL, &point.x, &point.y);
    size.w = point.x; 
    size.h = point.y;
}

int Hit::getDuration() const { return duration; }
void Hit::setDuration(int d) { duration = d; }
