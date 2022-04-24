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
#include "Level2.hpp"

SDL_Window* window;
SDL_Renderer* renderer;

void levels();
int loadMenu();
int loadLevel1();
int loadLevel2();

void setUp() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    window = SDL_CreateWindow(
        Common::TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        Common::WIDTH,
        Common::HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL 
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

    levels();

    quit();
    return 0;
}

void levels() {
    short stage = 2;
    for(;;) {
        switch(stage) {
        case 0:
            stage = loadMenu();         
            break;

        case 1:
            stage = loadLevel1();
            break;
        
        case 2:
            stage = loadLevel2();
            break;
        }
    }
}

int loadMenu() {
    Menu* menu = new Menu(renderer);
    int code = menu->update();
    delete menu;
    return code;
}

int loadLevel1() {
    Level1* level = new Level1(renderer);
    int code = level->loop();
    delete level;
    return code;
}

int loadLevel2() {
    Level2* level = new Level2(renderer);
    int code = level->loop();
    delete level;
    return code;
}