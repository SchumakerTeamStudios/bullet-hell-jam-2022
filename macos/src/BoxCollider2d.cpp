// 
// SchumakerTeam
// Hudson Schumaker
//

#include "BoxCollider2d.hpp"

BoxCollider2d::BoxCollider2d() : offset (Vector2d()), size (Dimension()) {}
BoxCollider2d::BoxCollider2d(int w, int h) : offset (Vector2d::zero()), size (Dimension(w, h)) {}
BoxCollider2d::BoxCollider2d(int x, int y, int w, int h) :  offset (Vector2d(x, y)), size (Dimension(w, h)) {}
BoxCollider2d::BoxCollider2d(Vector2d o, Dimension d) : offset(o), size(d) {}

bool BoxCollider2d::collide(const BoxCollider2d& a, const BoxCollider2d& b) {
    int pwA = a.offset.x + a.getWidth();
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

Vector2d BoxCollider2d::getSize() {
    return size;
}