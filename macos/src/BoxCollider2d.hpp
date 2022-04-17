// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once
#include "Common.hpp"

class BoxCollider2d final {

    private:
        Vector2d offset;
        Dimension size;

    public:
        BoxCollider2d();
        BoxCollider2d(short w, short h);
        BoxCollider2d(short x, short y, short w, short h);
        BoxCollider2d(Vector2d o, Dimension s);

        static bool collide(const BoxCollider2d& a, const BoxCollider2d& b);

        BoxCollider2d getBounds();
        Vector2d getLocation();
        Dimension getSize();
        short getX() const;
        short getY() const;
        short getWidth() const;
        short getHeight() const;
};