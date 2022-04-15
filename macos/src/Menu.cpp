


#include "Menu.hpp"

Menu::Menu(SDL_Renderer* renderer) {
    this->renderer = renderer;
    load();
    update();
}

Menu::~Menu() {
}

void Menu::load() {
    font60 = TTF_OpenFont("data/ExoSpace.ttf", 60);
    font24 = TTF_OpenFont("data/ExoSpace.ttf", 24);
    
    SDL_Surface* surfaceTitle = TTF_RenderText_Blended(font60, "Bullet Hell 2022", Color::getOrange());
    title = SDL_CreateTextureFromSurface(renderer, surfaceTitle);

    SDL_Surface* surfaceStartWhite = TTF_RenderText_Blended(font24, "- Press Enter to Start -", Color::getWhite());
    startWhiteTexture = SDL_CreateTextureFromSurface(renderer, surfaceStartWhite);

    SDL_Surface* surfaceStartGray = TTF_RenderText_Blended(font24, "- Press Enter to Start -", Color::getGray());
    startGrayTexture = SDL_CreateTextureFromSurface(renderer, surfaceStartGray);

    SDL_Surface* bkgSurface = IMG_Load("data/world.jpg");
    background = SDL_CreateTextureFromSurface(renderer, bkgSurface);
}

void Menu::update() {
    isRunning = true;
    while(isRunning) {
        int timeToWait = Common::MILLISECS_PER_FRAME - (SDL_GetTicks() - millisecsPreviousFrame);
        if (timeToWait > 0 && timeToWait <= Common::MILLISECS_PER_FRAME) {
            SDL_Delay(timeToWait);
        }
        deltaTime = (SDL_GetTicks() - millisecsPreviousFrame) / 1000.0;
        millisecsPreviousFrame = SDL_GetTicks();

        input();
        render();
        SDL_Delay(deltaTime);
    }
}

void Menu::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_Rect rectBkg = {
        0, 0, 800, 600 
    };
    SDL_RenderCopy(renderer, background, NULL, &rectBkg);

    SDL_Point size;
    SDL_QueryTexture(title, NULL, NULL, &size.x, &size.y);
    
    int speed = 8;
    float pi = 3.141592f;
    int offset = 20;
    
    SDL_Rect rect = { 
        Common::H_WIDTH - (size.x / 2), 
        static_cast<int>(speed * SDL_sin(SDL_GetTicks() * (pi / 1500.0f))) + offset,
        size.x,
        size.y 
    };
    SDL_RenderCopy(renderer, title, NULL, &rect);

    SDL_QueryTexture(startGrayTexture, NULL, NULL, &size.x, &size.y);
    SDL_Rect grayRect = { 
        Common::H_WIDTH - (size.x / 2), 
        Common::H_HEIGHT + 100 - (size.y / 2),
        size.x,
        size.y 
    };
    SDL_RenderCopy(renderer, startGrayTexture, NULL, &grayRect);

    SDL_QueryTexture(startWhiteTexture, NULL, NULL, &size.x, &size.y);
    SDL_Rect whiteRect = { 
        Common::H_WIDTH - (size.x / 2), 
        Common::H_HEIGHT + 100 - (size.y / 2) + 2,
        size.x,
        size.y 
    };
    SDL_RenderCopy(renderer, startWhiteTexture, NULL, &whiteRect);
    SDL_RenderPresent(renderer);   
}

void Menu::input() {
    SDL_Event sdlEvent;
    while (SDL_PollEvent(&sdlEvent)) {
        switch (sdlEvent.type) {
            case SDL_QUIT:
                isRunning = false;
                exit(0);
                break;
        }
    }
}

void Menu::unload() {
    SDL_DestroyTexture(title);
    TTF_CloseFont(font60);
    TTF_CloseFont(font24);
}