// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Enemy.hpp"
#define PI 3.14159265

Enemy::Enemy() : Sprite() {}
Enemy::Enemy(short x, short y, short w, short h, std::string sprtName, std::string ssfxName, 
    std::string ssgfxName, SDL_Renderer* renderer) : Sprite(x, y, w, h) {

    this->renderer = renderer;
    this->spriteName = sprtName;
    this->shootSfxName = ssfxName;
    this->shootGfxName = ssgfxName;
    init();
}

void Enemy::move(float deltaTime) {
    if (position.x < 660 && right) {
        position.x += 0.15f * deltaTime;
        if (position.x > 660) {
            right = false;
        }

    } 
    if (!right) {
        position.x -= 0.15f * deltaTime;
        if (position.x < 85) {
            right = true;
        }
    }
}

void Enemy::update(float deltaTime, std::vector<Bullet>* bullets) { 
    for (auto& pec : pecs) {
        if (SDL_GetTicks() - pec.lastEmissionTime > pec.repeatFrequency) {
            bullets->push_back(fire(&pec));
            pec.lastEmissionTime = SDL_GetTicks();
        }    
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
        
        if (hp < 50) SDL_SetTextureColorMod(sprite, 255, 0, 0);
        SDL_RenderCopy(renderer, sprite, &origin, &rect);
        
        BoxCollider2d box = getCollider();
        SDL_Rect collider; 
        collider.x = box.getX();
        collider.y = box.getY();
        collider.w = box.getWidth();
        collider.h = box.getHeight();
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        //SDL_RenderDrawRect(renderer, &collider);
    }
}

Bullet Enemy::fire(ProjectileEmitterComponent* pec) {
    Bullet bullet = Bullet(position.x + 17, position.y + 32, renderer);
    bullet.setTexture(shootTexture);
    bullet.colliderOffset.x = 12;
    bullet.colliderOffset.y = 12;
    bullet.colliderSize.w = 7;
    bullet.colliderSize.h = 7;

    float dx = cos(pec->angle * PI / 180.0f);
    float dy = sin(pec->angle * PI / 180.0f);
    bullet.dx = dx * pec->dx;
    bullet.dy = dy * pec->dy;
    bullet.speed = pec->speed;

    bullet.setWidth(32); 
    bullet.setHeight(32);
    Mix_PlayChannel(-1, shootSfx, 0);

    return bullet;
}

void Enemy::init() {
    animation = AnimationComponent(2, 4, true);
    colliderOffset.x = 10;
    colliderOffset.y = 10;
    colliderSize.w = 45;
    colliderSize.h = 40;

    load();
}

void Enemy::load() {
    std::string spriteTexturePath = "data/" + spriteName;
    SDL_Surface* idleSurface = IMG_Load(spriteTexturePath.c_str());
    setTexture(SDL_CreateTextureFromSurface(renderer, idleSurface));
    SDL_FreeSurface(idleSurface);

    std::string shootTexturePath = "data/" + shootGfxName;
    SDL_Surface* shootSurface = IMG_Load(shootTexturePath.c_str());
    shootTexture = SDL_CreateTextureFromSurface(renderer, shootSurface);
    SDL_FreeSurface(shootSurface);

    std::string shootSfxPath = "data/" + shootSfxName;
    shootSfx = Mix_LoadWAV(shootSfxPath.c_str());
}

void Enemy::unload() {
    Mix_FreeChunk(shootSfx);
}
