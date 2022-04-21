// 
// macos
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Common.hpp"
#include "Splash.hpp"
#include "Menu.hpp"
#include "Level1.hpp"

SDL_Window* window;
SDL_Renderer* renderer;

void setUp() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    window = SDL_CreateWindow(
        Common::TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        Common::WIDTH,
        Common::HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_METAL 
    );
    
    SDL_Surface* iconSurface = IMG_Load("data/joypad.png");
    SDL_SetWindowIcon(window, iconSurface);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);   
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
}

void quit() {
    SDL_Quit();
	TTF_Quit();
}

int main(int argc, char* argv[]) {
    setUp(); 

    Splash* splash = new Splash(renderer);
    delete splash;

    Menu* menu = new Menu(renderer);
    delete menu;

    Level1* level = new Level1(renderer);
    level->loop();

    quit();
    return 0;
}