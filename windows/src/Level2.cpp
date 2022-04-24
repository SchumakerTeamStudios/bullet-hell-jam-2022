// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Level2.hpp"

Level2::Level2(SDL_Renderer* renderer) {
    this->renderer = renderer;
    player = Player(356.0f, 535.0f - 80.0f, 64, 64, renderer);
    load();
}

Level2::~Level2() {
    unload();
}

int Level2::loop() {
    isRunning = true;
    currentTick = SDL_GetPerformanceCounter();

    while(isRunning) {
        input(); 
        update();
        collision();
        render(); 
    }
    return win;
}

void Level2::input() {
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_LEFT]) {
        player.move(-1, 0, deltaTime);
    }

    if (state[SDL_SCANCODE_RIGHT]) {
       player.move(1, 0, deltaTime);
    }

    if (state[SDL_SCANCODE_UP]) {
        player.move(0, -1, deltaTime);
    }

    if (state[SDL_SCANCODE_DOWN]) {
        player.move(0, 1, deltaTime);
    }

    SDL_Event e;
    while(SDL_PollEvent(&e)) {
      switch(e.type) {
            case SDL_QUIT:
                isRunning = false;
                exit(0);
            break;
      
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_s) {
                    bullets.push_back(player.fire());
                }
                if (e.key.keysym.sym == SDLK_a) {
                    bullets.push_back(player.fireLeft());
                }
                if (e.key.keysym.sym == SDLK_d) {
                    bullets.push_back(player.fireRight());
                }
            break;

            case SDL_KEYUP:
                player.move(0, 0, deltaTime);
            break;
        }
    }    
}

void Level2::update() {
    lastTick = currentTick;
	currentTick = SDL_GetPerformanceCounter();
	deltaTime = (float)((currentTick - lastTick) * 1000.0f / (float)SDL_GetPerformanceFrequency());

    if (enemies.size() == 0) {
        isRunning = false; 
        win = 0;  
    } 
    
    if (player.hp <= 0) {
        isRunning = false; 
        win = 0;
    } 
    
    for (long i = 0; i < enemies.size(); i++) {
        if (enemies.at(i).hp < 0) {
            enemies.erase(enemies.begin() + i); 
        }
    }

    for (long i = 0; i < bullets.size(); i++) {
        if (bullets.at(i).isExpired() || bullets.at(i).destroyed) {
            bullets.erase(bullets.begin() + i); 
        }
    }

    for (long i = 0; i < enemiesBullets.size(); i++) {
        if (enemiesBullets.at(i).isExpired() || enemiesBullets.at(i).destroyed) {
            enemiesBullets.erase(enemiesBullets.begin() + i); 
        }
    }

    for (auto& bullet : bullets) {
        bullet.move(deltaTime);
    }

    for (auto& bullet : enemiesBullets) {
        bullet.move(deltaTime);
    }

    for (int i = 0; i < hits.size(); i++) {
        if (hits.at(i).isExpired()) {
            hits.erase(hits.begin() + i); 
        }
    }

    for (auto& e : enemies) {
        e.update(deltaTime, &enemiesBullets);
        e.move(deltaTime);
    }

    if (player.hp > 0) player.update(deltaTime);
}

void Level2::collision() {
    for (auto& bullet : bullets) {
        for (auto& o: enemies) {
            if (BoxCollider2d::collide(bullet.getCollider(), o.getCollider())) {
                o.hp--;
                bullet.destroyed = true;
                hits.push_back(Hit(bullet.getX(), bullet.getY(), renderer));
                Mix_PlayChannel(-1, explodeSfx, 0);
            }
        }
    }

    for (auto& bullet : enemiesBullets) {
        if (BoxCollider2d::collide(bullet.getCollider(), player.getCollider())) {
            player.hp--;
            bullet.destroyed = true;
            Mix_PlayChannel(-1, explodeSfx, 0);
        }
    }
}

void Level2::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, NULL, &rectBackground);
    //SDL_RenderCopy(renderer, water, NULL, &rectBackground);

    for (auto& o : enemies) {
        o.draw();
    }

    if (player.hp > 0) player.draw();

    for (auto& bullet : bullets) {
        bullet.draw();
    } 

    for (auto& bullet : enemiesBullets) {
        bullet.draw();
    } 

    for (auto& hit : hits) {
        hit.draw();
    } 

    SDL_RenderPresent(renderer);     
}

void Level2::load() {
    SDL_Surface* backgroundSurface = IMG_Load("data/back1s3.png");
    background = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface); 

    //SDL_Surface* waterSurface = IMG_Load("data/water.png");
    //water = SDL_CreateTextureFromSurface(renderer, waterSurface); 
    explodeSfx = Mix_LoadWAV("data/explode.mp3");

    Enemy skullBazuka = Enemy(650, 64, 64, 64, "skullzooka.png", "laser.mp3", "enemieshoot2.png", renderer);
    skullBazuka.hp = 120;
    skullBazuka.type = 1;
    skullBazuka.colliderOffset.x = 10;
    skullBazuka.colliderOffset.y = 5;
    skullBazuka.colliderSize.w = 45;
    skullBazuka.colliderSize.h = 40;
    skullBazuka.fireOffsetX = -6;
    skullBazuka.fireOffsetY = 18;
   
    ProjectileEmitterComponent pec = ProjectileEmitterComponent(-1, 1);
    pec.speed = 0.4f;
    pec.angle = 1;
    pec.repeatFrequency = 800;
    skullBazuka.pecs.push_back(pec);
    enemies.push_back(skullBazuka);  

    Enemy skullOrb = Enemy(400, 40, 64, 64, "skullorb.png", "laser.mp3", "enemieshoot1.png", renderer);
    skullOrb.hp = 100;
    skullOrb.fireOffsetX = 17;
    skullOrb.fireOffsetY = 32;
   
    ProjectileEmitterComponent pec2 = ProjectileEmitterComponent(1, 1);
    pec2.speed = 0.3f;
    pec2.angle = 15;
    pec2.repeatFrequency = 1000;
    skullOrb.pecs.push_back(pec2);

    ProjectileEmitterComponent pec3 = ProjectileEmitterComponent(-1, 1);
    pec3.speed = 0.3f;
    pec3.angle = 15;
    pec3.repeatFrequency = 1000;
    skullOrb.pecs.push_back(pec3);

    ProjectileEmitterComponent pec4 = ProjectileEmitterComponent(-1, 1);
    pec4.speed = 0.2f;
    pec4.angle = 90;
    pec4.repeatFrequency = 875;
    skullOrb.pecs.push_back(pec4);

    enemies.push_back(skullOrb);  
}

void Level2::unload() {
    SDL_DestroyTexture(background);
    Mix_FreeChunk(explodeSfx);
}