// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Player.hpp"

Player::Player() : Sprite() {};
Player::Player(int x, int y) : Sprite(x, y) {};
Player::Player(int x, int y, int w, int h) : Sprite(x, y, w, h) {};
Player::Player(Vector2d position, Dimension size) : Sprite(position, size) {};
        
void Player::move(int dx, int dy) {
    position.x += dx;
    position.y += dy;
}

void Player::draw(SDL_Renderer* renderer) {
    SDL_Rect rect = { position.x, position.y, size.w, size.h };
    SDL_Rect origin = {0, 0, 64, 64 };
    SDL_RenderCopy(renderer, sprite, &origin, &rect);
}

void Player::init() {

}

void Player::load() {

}