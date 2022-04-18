// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Player.hpp"

Player::Player() : Sprite() {};
Player::Player(short x, short y, short w, short h, SDL_Renderer* renderer) : Sprite(x, y, w, h) {
    this->renderer = renderer;
    init();
    load();
}
Player::Player(Vector2d position, Dimension size, SDL_Renderer* renderer) : Sprite(position, size) {
    this->renderer = renderer;
    init();
    load();
}
        
void Player::move(short dx, short dy, float deltaTime) {
    if(dx < 0) {
        setTexture(moveLeftTexture);
        currentAnimation = &moveLeftAnimation;
    } else if(dx > 0) {
        setTexture(moveRightTexture);
        currentAnimation = &moveRightAnimation;
    } else {
        if (currentAnimation != &idleAnimation) {
            setTexture(idleTexture);  
            currentAnimation = &idleAnimation;
        }
    }

    position.x += dx * 0.25f * deltaTime;
    position.y += dy * 0.25f * deltaTime;
}

void Player::draw() {
    currentAnimation->currentFrame = ((SDL_GetTicks() - currentAnimation->startTime) 
        * currentAnimation->frameSpeedRate / 1000) % currentAnimation->numFrames;

    SDL_Rect origin = { currentAnimation->currentFrame * size.w , 0, size.w, size.h };
    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = size.w;
    rect.h = size.h;

    SDL_RenderCopy(renderer, sprite, &origin, &rect);
}

void Player::init() {
    idleAnimation = AnimationComponent(3, 4, true);
    moveLeftAnimation = AnimationComponent(4, 6, true);
    moveRightAnimation = AnimationComponent(4, 6, true);
    shootLeftAnimation = AnimationComponent(3, 4, true);
    shootRightAnimation = AnimationComponent(3, 4, true);
    shootUpAnimation = AnimationComponent(4, 6, true);

    currentAnimation = &idleAnimation;
}

void Player::load() {
    SDL_Surface* idleSurface = IMG_Load("data/moveidle.png");
    idleTexture = SDL_CreateTextureFromSurface(renderer, idleSurface);

    SDL_Surface* moveLeftSurface = IMG_Load("data/moveleft.png");
    moveLeftTexture = SDL_CreateTextureFromSurface(renderer, moveLeftSurface);

    SDL_Surface* moveRightSurface = IMG_Load("data/moveright.png");
    moveRightTexture = SDL_CreateTextureFromSurface(renderer, moveRightSurface);

    SDL_Surface* shootLeftSurface = IMG_Load("data/shootleft.png");
    shootLeftTexture = SDL_CreateTextureFromSurface(renderer, shootLeftSurface);

    SDL_Surface* shootRightSurface = IMG_Load("data/shootright.png");
    shootRightTexture = SDL_CreateTextureFromSurface(renderer, shootRightSurface);

    SDL_Surface* shootUpSurface = IMG_Load("data/shootup.png");
    shootUpTexture = SDL_CreateTextureFromSurface(renderer, shootUpSurface);

    setTexture(idleTexture); 

    SDL_FreeSurface(idleSurface);
    SDL_FreeSurface(moveLeftSurface);
    SDL_FreeSurface(moveRightSurface);
    SDL_FreeSurface(shootLeftSurface);
    SDL_FreeSurface(shootRightSurface);
    SDL_FreeSurface(shootUpSurface);
}