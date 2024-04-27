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

	float velocityMag;

	float rotation;

	float dragForce;

	//Style
	Color color;

	//Extern
	int checkPoint;
};

