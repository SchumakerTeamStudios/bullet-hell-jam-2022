// 
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
        BoxCollider2d(int w, int h);
        BoxCollider2d(int x, int y, int w, int h);
        BoxCollider2d(Vector2d o, Dimension s);

        static bool collide(const BoxCollider2d& a, const BoxCollider2d& b);

        BoxCollider2d getBounds();
        Vector2d getLocation();
        Vector2d getSize();
};