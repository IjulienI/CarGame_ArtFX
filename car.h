#pragma once
#include "constant.h"
#include <cmath>
#include <iostream>

class Car
{
public:
	Car();
	Car(Vector2 position, float rotation);
	~Car();

	void Init();
	void Update(float dt);
	void Draw();
private:
	//Movements (base)
	Vector2 position;
	Vector2 velocity;

	float maxVelocity;
	float maxVelocityBack;
	float acceleration;
	float velocityMag;

	float rotation;
	float rotationAcceleration;
	float maxRotationSpeed;
	int minSpeedForRotation;

	float dragForce;
	float baseDrag;
	float handBrakeDrag;

	//Style
	Vector2 size;
	Color color;

	//For Draw
	Vector2 center;

	//Extern
	int checkPoint;
};

