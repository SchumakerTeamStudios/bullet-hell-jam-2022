// 
// Bullet Hell Jam 2022
// SchumakerTeam
// Hudson Schumaker
//

#include "Canvas.hpp"

Canvas::Canvas() : w(screenWidth), h(screenHeight) {}
Canvas::Canvas(int w, int h) : w(w), h(h) {}

void Canvas::setWidth(int w) { this->w = w; };
int Canvas::getWidth() const { return w; };

void Canvas::setHeight(int h) { this->h = h; };
int Canvas::getHeight() const { return h; };