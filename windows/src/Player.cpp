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

    if (position.x > 80 && position.x < 674)  {
        position.x += dx * 0.25f * deltaTime;
        if (position.x > 674) {
            position.x = 673;
        }

        if (position.x < 80) {
            position.x = 81;
        }
    } 

    if (position.y > 80 && position.y < 460) { 
        position.y += dy * 0.25f * deltaTime;
        if (position.y > 460) {
            position.y = 459;
        }

        if (position.y < 80) {
            position.y = 81;
        }
    }
    //std::cout << position.x << " " << position.y << std::endl;
}

void Player::update(float deltaTime) {
    for (int i = 0; i < bullets.size(); i++) {
        if (bullets.at(i).isExpired()) {
            bullets.erase(bullets.begin() + i); 
        }
    }

    for(auto& bullet : bullets) {
        bullet.move(deltaTime);
    }

    //std::cout << bullets.size() << std::endl;

}

void Player::draw() {
    currentAnimation->currentFrame = ((SDL_GetTicks() - currentAnimation->startTime) 
        * currentAnimation->frameSpeedRate / 1000) % currentAnimation->numFrames;

    SDL_Rect origin = { currentAnimation->currentFrame * size.w, 0, size.w, size.h };
    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = size.w;
    rect.h = size.h;

    SDL_RenderCopy(renderer, sprite, &origin, &rect);

    for(auto& bullet : bullets) {
        bullet.draw();
    } 
}

void Player::fire() {
    Bullet bullet = Bullet(position.x + 26, position.y - 18, renderer);
    bullet.setTexture(shoot);
    bullet.dx = 0;
    bullet.dy = -1;

    bullet.setWidth(32); 
    bullet.setHeight(32);

    bullets.push_back(bullet);
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
    setTexture(idleTexture); 

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

    SDL_Surface* shootSurface = IMG_Load("data/shoot4.png");
    shoot = SDL_CreateTextureFromSurface(renderer, shootSurface);

    SDL_FreeSurface(idleSurface);
    SDL_FreeSurface(moveLeftSurface);
    SDL_FreeSurface(moveRightSurface);
    SDL_FreeSurface(shootLeftSurface);
    SDL_FreeSurface(shootRightSurface);
    SDL_FreeSurface(shootUpSurface);
    SDL_FreeSurface(shootSurface);
}

void Player::unload() {
    SDL_DestroyTexture(idleTexture);
    SDL_DestroyTexture(moveLeftTexture);
    SDL_DestroyTexture(moveRightTexture);
    SDL_DestroyTexture(shootLeftTexture);
    SDL_DestroyTexture(shootRightTexture);
    SDL_DestroyTexture(shootUpTexture);
}