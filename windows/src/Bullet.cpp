// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Bullet.hpp"

Bullet::Bullet() : Sprite() {};
Bullet::Bullet(short x, short y, SDL_Renderer* renderer) : Sprite(x, y, 0, 0) {
    this->renderer = renderer;
    init();
    load();
} 

void Bullet::draw() {

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

void Bullet::move(float deltaTime) {
    position.x += dx * speed * deltaTime;
    position.y += dy * speed * deltaTime;
}

bool Bullet::isExpired() {
    return (SDL_GetTicks() - startTime) > duration;
}

void Bullet::init() {
    startTime = SDL_GetTicks();
    animation = AnimationComponent(2, 4, true);
}

void Bullet::load() {

}

float Bullet::getSpeed() const { return speed; }
void Bullet::setSpeed(float s) { speed = s; }
int Bullet::getDuration() const { return duration; }
void Bullet::setDuration(int d) { duration = d; }
