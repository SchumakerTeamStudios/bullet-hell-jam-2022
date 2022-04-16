// 
// macOS
// SchumakerTeam
// Hudson Schumaker
//

#pragma once

template <typename T> struct Vector2d {
    T x = 0;
    T y = 0;
    
    Vector2d() {}
    Vector2d(T x, T y) : x(x), y(y) {}
    
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
        return new Vector2d(0, 1);
    }
};

using Vector2di = Vector2d<int>;
using Vector2df = Vector2d<float>;