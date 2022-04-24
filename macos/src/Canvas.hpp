// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"

class Canvas {

    private:
        int w, h;

    public:
        static const int screenWidth = 800;
        static const int screenHeight = 600;
        
        Canvas();
        Canvas(int w, int h);

        virtual int loop() = 0;
        virtual void input() = 0; 
        virtual void update() = 0;
        virtual void collision() = 0;
        virtual void render() = 0;
        virtual void load() = 0;
        virtual void unload() = 0;
        
        void setWidth(int w);
	    int getWidth() const;

	    void setHeight(int h);
	    int getHeight() const;
};