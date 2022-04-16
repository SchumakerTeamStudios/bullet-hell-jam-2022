// 
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"

class Sprite {

    protected:
        Vector2d position;
        Dimension size;

    private:
        SDL_Texture* sprite;

    public:
        Sprite();
	    Sprite(short x, short y);
        Sprite(short x, short y, short w, short h);
        Sprite(Vector2d p, Dimension s);

        virtual void draw(SDL_Renderer* renderer) = 0;
	    Dimension getBounds();
	    void setTexture(SDL_Texture* spr);
		
        short getX() const;
	    void setX(short x);

        short getY() const;
        void setY(short y);

        short getWidth() const;
        void setWidth(short w);

	    short getHeight() const;
   	    void setHeight(short h);
};