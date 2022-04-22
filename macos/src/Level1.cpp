// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Level1.hpp"

Level1::Level1(SDL_Renderer* renderer) {
    this->renderer = renderer;
    player = Player(356.0f, 535.0f - 80.0f, 64, 64, renderer);
    load();
}

Level1::~Level1() {
    unload();
}

bool Level1::loop() {
    isRunning = true;
    currentTick = SDL_GetPerformanceCounter();

    while(isRunning) {
        input(); 
        update();
        collision();
        render(); 
    }
    return true;
}

void Level1::input() {
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

void Level1::update() {
    lastTick = currentTick;
	currentTick = SDL_GetPerformanceCounter();
	deltaTime = (float)((currentTick - lastTick) * 1000.0f / (float)SDL_GetPerformanceFrequency());

    for (int i = 0; i < bullets.size(); i++) {
        if (bullets.at(i).isExpired() || bullets.at(i).destroyed) {
            bullets.erase(bullets.begin() + i); 
        }
    }

    for (int i = 0; i < enemiesBullets.size(); i++) {
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

    for(auto& e : enemies) {
        e.update(deltaTime, &enemiesBullets);
    }

    player.update(deltaTime);
}

void Level1::collision() {
     for (auto& bullet : bullets) {
        for (auto& o: enemies) {
            if (BoxCollider2d::collide(bullet.getCollider(), o.getCollider())) {
                bullet.destroyed = true;
                hits.push_back(Hit(bullet.getX(), bullet.getY(), renderer));
                Mix_PlayChannel(-1, explodeSfx, 0);
            }
        }
    }
}

void Level1::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    SDL_RenderCopy(renderer, background, NULL, &rectBackground);

    for (auto& o : enemies) {
        o.draw();
    }

    player.draw();

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

void Level1::load() {
    SDL_Surface* backgroundSurface = IMG_Load("data/back1s1.png");
    background = SDL_CreateTextureFromSurface(renderer, backgroundSurface); 

    explodeSfx = Mix_LoadWAV("data/explode.mp3");

    Enemy object = Enemy(120, 40, 64, 64, "skullorb.png", "laser.mp3", "enemieshoot1.png", renderer);
    object.pec = ProjectileEmitterComponent(0, 1);
    object.pec.speed = 0.25f;
    object.pec.angle = 45.0f;
    object.pec.repeatFrequency = 1000;
    enemies.push_back(object);  

    //Enemy object2 = Enemy(480, 80, 64, 64, "skullorb.png", "laser.mp3", "enemieshoot1.png", renderer);
    //enemies.push_back(object2);

    //Enemy object3 = Enemy(480, 120, 64, 64, "skullorb.png", "laser.mp3", "enemieshoot1.png", renderer);
    //enemies.push_back(object3);  

    //Enemy object4 = Enemy(120, 160, 64, 64, "skullorb.png", "laser.mp3", "enemieshoot1.png", renderer);
    //enemies.push_back(object4);  
}

void Level1::unload() {
    SDL_DestroyTexture(background);
}
