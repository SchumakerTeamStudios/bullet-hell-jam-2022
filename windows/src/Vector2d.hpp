// 
// macOS
// SchumakerTeam
// Hudson Schumaker
//

#pragma once

struct Vector2d {
    short x = 0.0f;
    short y = 0.0f;
    
    Vector2d() {}
    Vector2d(short x, short y) : x(x), y(y) {}
    
    static Vector2d foward(){
        return Vector2d(1, 0);
    }

    static Vector2d backward() {
        return Vector2d(-1, 0);
    }

    static Vector2d up() {
        return Vector2d(0, -1);
    }

    static Vector2d down() {
        return Vector2d(0, 1);
    }
};
