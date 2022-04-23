// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"
#include "BoxCollider2d.hpp"

class Sprite {

    protected:
        Vector2d position;
        Dimension size;
        SDL_Texture* sprite;
        
    public:
        Sprite();
	    Sprite(short x, short y);
        Sprite(short x, short y, short w, short h);
        Sprite(Vector2d p, Dimension s);

        virtual void draw() = 0;
	    Dimension getBounds();
        BoxCollider2d getCollider();
	    void setTexture(SDL_Texture* spr);

		Vector2d colliderOffset;
        Dimension colliderSize;

        short getX() const;
	    void setX(short x);

        short getY() const;
        void setY(short y);

        short getWidth() const;
        void setWidth(short w);

	    short getHeight() const;
   	    void setHeight(short h);
};