// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Player.hpp"

Player::Player() : Sprite() {};
Player::Player(int x, int y, int w, int h, SDL_Renderer* renderer) : Sprite(x, y, w, h) {
    this->renderer = renderer;
}
Player::Player(Vector2d position, Dimension size, SDL_Renderer* renderer) : Sprite(position, size) {
    this->renderer = renderer;
}
        
void Player::move(int dx, int dy) {
    position.x += dx;
    position.y += dy;
}

void Player::draw() {
    SDL_Rect rect = { position.x, position.y, size.w, size.h };
    SDL_Rect origin = { 0, 0, 64, 64 };
    SDL_RenderCopy(renderer, sprite, &origin, &rect);
}

void Player::init() {
    idleAnimation = AnimationComponent(3, 10, true);
    moveLeftAnimation = AnimationComponent(4, 10, true);
    moveRightAnimation = AnimationComponent(4,10, true);
    shootLeftAnimation = AnimationComponent(3, 10, true);
    shootRightAnimation = AnimationComponent(3, 10, true);
    shootUpAnimation = AnimationComponent(4, 10, true);
}

void Player::load() {
    SDL_Surface* idleSuface = IMG_Load("data/moveidle.png");
    idleTexture = SDL_CreateTextureFromSurface(renderer, idleSuface);

    SDL_Surface* moveLeftSuface = IMG_Load("data/moveleft.png");
    moveLeftTexture = SDL_CreateTextureFromSurface(renderer, moveLeftSuface);

    SDL_Surface* moveRightSuface = IMG_Load("data/moveright.png");
    moveRightTexture = SDL_CreateTextureFromSurface(renderer, moveRightSuface);

    SDL_Surface* shootLeftSurface = IMG_Load("data/shootleft.png");
    shootLeftTexture = SDL_CreateTextureFromSurface(renderer, shootLeftSurface);

    SDL_Surface* shootRightSurface = IMG_Load("data/shootright.png");
    shootRightTexture = SDL_CreateTextureFromSurface(renderer, shootRightSurface);

    SDL_Surface* shootUpSurface = IMG_Load("data/shootup.png");
    shootUpTexture = SDL_CreateTextureFromSurface(renderer, shootUpSurface);

    SDL_FreeSurface(idleSuface);
    SDL_FreeSurface(moveLeftSuface);
    SDL_FreeSurface(moveRightSuface);
    SDL_FreeSurface(shootLeftSurface);
    SDL_FreeSurface(shootRightSurface);
    SDL_FreeSurface(shootUpSurface);
}