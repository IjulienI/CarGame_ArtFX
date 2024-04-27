#pragma once
#include "constant.h"
#include <cmath>
#include <iostream>
#include "raylib/raymath.h"

class Car
{
public:
	Car();
	Car(Vector2 position);
	~Car();
	void Init();
	void Update(float dt);
	void Draw();
private:
	//Movements
	Vector2 position;
	Vector2 velocity;

	float maxVelocity;
	float maxVelocityBack;
	float acceleration;
	float velocityMag;

	float rotation;
	float rotationAcceleration;

	float dragForce;
	float baseDrag;
	float handBrakeDrag;

	//Style
	Vector2 size;
	Color color;

	Vector2 center;
};

