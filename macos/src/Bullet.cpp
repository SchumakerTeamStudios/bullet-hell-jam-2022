// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Bullet.hpp"

Bullet::Bullet() : Sprite() {};
Bullet::Bullet(short x, short y, short w, short h, SDL_Renderer* renderer) : Sprite(x, y, w, h) {
    this->renderer = renderer;
    init();
    load();
} 

Bullet::~Bullet() {}

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

}

void Bullet::load() {

}
