// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Sprite.hpp"

Sprite::Sprite() : position(Vector2d()), size(Dimension()) {}
Sprite::Sprite(short x, short y) : position(Vector2d(x, y)), size(Dimension()) {}
Sprite::Sprite(short x, short y, short w, short h) : position(Vector2d(x, y)), size(Dimension(w, h)) {}
Sprite::Sprite(Vector2d p, Dimension s) : position(p), size(s) {}

void Sprite::setTexture(SDL_Texture* spr) {
	sprite = spr; 
}

BoxCollider2d Sprite::getCollider() {
    Vector2d  colliderPosition = { position.x + colliderOffset.x, position.y + colliderOffset.y };  
    return BoxCollider2d(colliderPosition, colliderSize);
}

Dimension Sprite::getBounds() {
    return size;
}

short Sprite::getX() const { return position.x; };
void Sprite::setX(short x) { position.x = x; };

short Sprite::getY() const { return position.y; };
void Sprite::setY(short y) { position.y = y; };

short Sprite::getWidth() const { return size.w; };
void Sprite::setWidth(short w) { size.w = w; };

short Sprite::getHeight() const { return size.h; };
void Sprite::setHeight(short h) { size.h = h; };
