// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Object.hpp"

Object::Object() : Sprite() {}
Object::Object(short x, short y, SDL_Renderer* renderer) : Sprite(x, y, 0, 0) {
    init();
}

void Object::draw() {
    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = size.w;
    rect.h = size.h;

    SDL_RenderCopy(renderer, sprite, NULL, &rect);
}

void Object::init() {
    load();
}

void Object::load() {
    SDL_Surface* surface = IMG_Load("data/happyblock.png");
    setTexture(SDL_CreateTextureFromSurface(renderer, surface)); 
    SDL_Point point;
    SDL_QueryTexture(sprite, NULL, NULL, &point.x, &point.y);
    size.w = point.x; 
    size.h = point.y;
}
