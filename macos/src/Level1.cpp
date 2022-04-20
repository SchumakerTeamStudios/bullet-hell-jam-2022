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
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
        switch(e.type) {
            case SDL_QUIT:
                isRunning = false;
                exit(0);
            break;
            
            case SDL_KEYDOWN:
                if (e.key.keysym.sym == SDLK_SPACE) {
                    bullets.push_back(player.fire());
                }
                if (e.key.keysym.sym == SDLK_LEFT) {
                    player.move(-1, 0, deltaTime);
                }
                if (e.key.keysym.sym == SDLK_RIGHT) {
                    player.move(1, 0, deltaTime);
                }
                if (e.key.keysym.sym == SDLK_UP) {
                    player.move(0, -1, deltaTime);
                }
                if (e.key.keysym.sym == SDLK_DOWN) {
                    player.move(0, 1, deltaTime);
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
        if (bullets.at(i).isExpired()) {
            bullets.erase(bullets.begin() + i); 
        }
    }

    for (auto& bullet : bullets) {
        bullet.move(deltaTime);
    }

    player.update(deltaTime);
}

void Level1::collision() {
     for (auto& bullet : bullets) {
        if (BoxCollider2d::collide(bullet.getCollider(), objects.at(0).getCollider())) {
            objects.at(0).getX();
            hits.push_back(Hit(objects.at(0).getX(),  objects.at(0).getY(), renderer));
        }
    }
}

void Level1::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    SDL_RenderCopy(renderer, background, NULL, &rectBackground);

    for (auto& o : objects) {
        o.draw();
    }

    player.draw();

    for (auto& bullet : bullets) {
        bullet.draw();
    } 

    for (auto& hit : hits) {
        hit.draw();
    } 

    SDL_RenderPresent(renderer);     
}

void Level1::load() {
    SDL_Surface* backgroundSurface = IMG_Load("data/scenario2.png");
    background = SDL_CreateTextureFromSurface(renderer, backgroundSurface); 

    Object object = Object(120, 120, renderer);
    objects.push_back(object);  
}

void Level1::unload() {
    SDL_DestroyTexture(background);
}
