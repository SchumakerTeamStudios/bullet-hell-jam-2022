compile:
	g++ -Wall -std=c++17 -O3 src/*.cpp -o game -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_gfx
	mv -f game build/

run:
	./build/game

clean:
	rm ./build/game