// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Enemy.hpp"

Enemy::Enemy() : Sprite() {}
Enemy::Enemy(short x, short y, short w, short h, std::string sprtName, std::string ssfxName, 
    std::string ssgfxName, SDL_Renderer* renderer) : Sprite(x, y, w, h) {

    this->renderer = renderer;
    this->spriteName = sprtName;
    this->shootSfxName = ssfxName;
    this->shootGfxName = ssgfxName;
    init();
}

void Enemy::move(short dx, short dy, float deltaTime) {

}

void Enemy::update(float deltaTime, std::vector<Bullet>* bullets) { 

    if (SDL_GetTicks() - pec.lastEmissionTime > pec.repeatFrequency) {
        bullets->push_back(fire());
        pec.lastEmissionTime = SDL_GetTicks();
    }    
}

void Enemy::draw() {
   if (!destroyed) {
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
}

Bullet Enemy::fire() {
    Bullet bullet = Bullet(position.x, position.y, renderer);
    bullet.setTexture(shootTexture);
    bullet.dx = pec.dx;
    bullet.dy = pec.dy;
    bullet.speed = pec.speed;

    bullet.setWidth(32); 
    bullet.setHeight(32);
    Mix_PlayChannel(-1, shootSfx, 0);

    return bullet;
}

void Enemy::init() {
    animation = AnimationComponent(2, 4, true);
    load();
}

void Enemy::load() {
    std::string spriteTexturePath = "data/" + spriteName;
    SDL_Surface* idleSurface = IMG_Load(spriteTexturePath.c_str());
    setTexture(SDL_CreateTextureFromSurface(renderer, idleSurface));

    std::string shootTexturePath = "data/" + shootGfxName;
    SDL_Surface* shootSurface = IMG_Load(shootTexturePath.c_str());
    shootTexture = SDL_CreateTextureFromSurface(renderer, shootSurface);

    std::string shootSfxPath = "data/" + shootSfxName;
    shootSfx = Mix_LoadWAV(shootSfxPath.c_str());
}

void Enemy::unload() {
    
}
