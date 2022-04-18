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
    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = size.w;
    rect.h = size.h;

    SDL_RenderCopy(renderer, sprite, NULL, &rect);
}

void Bullet::move(short dx, short dy, float deltaTime) {
    position.x += dx * 0.25f * deltaTime;
    position.y += dy * 0.25f * deltaTime;
}

void Bullet::init() {
    startTime = SDL_GetTicks();

}

void Bullet::load() {

}

float Bullet::getSpeed() const { return speed; }
void Bullet::setSpeed(float s) { speed = s; }
int Bullet::getDuration() const { return duration; }
void Bullet::setDuration(int d) { duration = d; }
