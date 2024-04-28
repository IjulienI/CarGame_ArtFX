#ifndef CONSTANT_H
#define CONSTANT_H

#include <raylib.h>

//BASE

const Vector2 WINDOW_SIZE = { 1080,720 };
const int FRAME_LIMIT = 60;
const Color BACKGROUND_COLOR = BLACK;
const int PIXELS_PER_METER = 5;

//CAR

const Vector2 CAR_SIZE = { 25,10,};

const int CAR_MAX_VELOCITY = 350;
const int CAR_MAX_BACK_VELOCITY = CAR_MAX_VELOCITY / 2.0;
const int CAR_ACCELERATION = 100;

const int CAR_ROTATION_ACCELERATION = 15000;
const int CAR_MAX_ROTATION_SPEED = 150;
const int CAR_MIN_SPEED_ROTATION = 30;

const float CAR_DRAG_FORCE = .2;
const int CAR_HANDBRAKE_DRAG = 4;

const Vector2 CAR_CENTER = { CAR_SIZE.x ,CAR_SIZE.y / 2 };

//TILES

const int TILE_SIZE = 64;
const Vector2 TILE_NUM = { (int)(WINDOW_SIZE.x / TILE_SIZE), (int)(WINDOW_SIZE.y / TILE_SIZE) };
const Vector2 TILE_SPACER = {(TILE_SIZE * 0.875) / 2,(TILE_SIZE * 0.25) / 2};// Je sors pas les chiffres au pif, j'ai calculé mais je savais pas comment récupérer seulement décimales...

#endif