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

void loadMenu();
bool loadLevel1();

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
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 256);
}

void quit() {
    SDL_Quit();
	TTF_Quit();
}

int main(int argc, char* argv[]) {
    setUp(); 

    Splash* splash = new Splash(renderer);
    delete splash;

    loadMenu();

    if (!loadLevel1()) {
        loadMenu();
    } 

    quit();
    return 0;
}

void loadMenu() {
    Menu menu = Menu(renderer);
}


bool loadLevel1() {
    Level1 level = Level1(renderer);
    return level.loop();
}