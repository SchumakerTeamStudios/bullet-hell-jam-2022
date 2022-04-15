compile:
	g++ -Wall -std=c++17 -O3 macos/src/*.cpp -o game -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_gfx
	mv -f game macos/build/

run:
	./macos/build/game

clean:
	rm /macos/build/game