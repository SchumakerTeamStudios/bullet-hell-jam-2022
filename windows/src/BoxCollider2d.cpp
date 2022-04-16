// 
// SchumakerTeam
// Hudson Schumaker
//

#include "BoxCollider2d.hpp"

BoxCollider2d::BoxCollider2d() : offset (Vector2d()), size (Dimension()) {}
BoxCollider2d::BoxCollider2d(short w, short h) : offset (Vector2d()), size (Dimension(w, h)) {}
BoxCollider2d::BoxCollider2d(short x, short y, short w, short h) : offset (Vector2d(x, y)), size (Dimension(w, h)) {}
BoxCollider2d::BoxCollider2d(Vector2d o, Dimension d) : offset(o), size(d) {}

bool BoxCollider2d::collide(const BoxCollider2d& a, const BoxCollider2d& b) {
    int pwA = a.getX() + a.getWidth();
    int pwB = b.getX() + b.getWidth();

    int phA = a.getY() + a.getHeight();
    int phB = b.getY() + b.getHeight();

    if (pwA > b.getX() && a.getX() < pwB && phA > b.getY() && a.getY() < phB) {
        return true;
    }
    return false;
}

BoxCollider2d BoxCollider2d::getBounds() {
    return BoxCollider2d(offset, size);
}

Vector2d BoxCollider2d::getLocation() {
    return offset;
}

Dimension BoxCollider2d::getSize() {
    return size;
}

short BoxCollider2d::getX() const {
    return offset.x;
}

short BoxCollider2d::getY() const {
    return offset.y;
}

short BoxCollider2d::getWidth() const {
    return size.w;
}

short BoxCollider2d::getHeight() const {
    return size.h;
}