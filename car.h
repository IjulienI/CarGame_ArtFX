#pragma once
#include "constant.h"
#include <cmath>
#include <iostream>

class Car
{
public:
	Car();
	Car(Vector2 position, float rotation, Color color);
	~Car();

	void Init();
	void Update(float dt);
	void Draw();
private:
	//Movements (base)
	Vector2 position;
	Vector2 velocity;

	int maxVelocity;
	int maxVelocityBack;
	int acceleration;
	float velocityMag;

	float rotation;
	int rotationAcceleration;
	int maxRotationSpeed;
	int minSpeedForRotation;

	float dragForce;
	float baseDrag;
	int handBrakeDrag;

	//Style
	Vector2 size;
	Color color;

	//For Draw
	Vector2 center;

	//Extern
	int checkPoint;
};

