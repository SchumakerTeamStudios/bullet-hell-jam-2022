// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#pragma once

struct Vector2d {
    float x = 0.0f;
    float y = 0.0f;
    
    Vector2d() {}
    Vector2d(float x, float y) : x(x), y(y) {}
    
    static Vector2d foward(){
        return Vector2d(1.0f, 0.0f);
    }

    static Vector2d backward() {
        return Vector2d(-1.0f, 0.0f);
    }

    static Vector2d up() {
        return Vector2d(0.0, -1.0f);
    }

    static Vector2d down() {
        return Vector2d(0.0f, 1.0f);
    }
};
