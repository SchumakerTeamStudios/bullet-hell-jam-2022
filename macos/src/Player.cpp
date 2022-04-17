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
    
}

void Player::draw(SDL_Renderer* renderer) {
    SDL_Rect rect = { position.x, position.y, size.w, size.h };
    SDL_RenderCopy(renderer, sprite, NULL, &rect);
}