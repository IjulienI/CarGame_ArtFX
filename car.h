#pragma once
#include "constant.h"
#include <cmath>
#include <iostream>
#include "tile.h"

class Car
{
public:
	Car();
	Car(Vector2 position, float rotation, Color color);
	~Car();

	void Init();
	void Update(float dt);
	void Draw();

	bool IsIn(Tile& tile);
	void SetOnRoad(bool onRoad);
private:
	//Movements (base)
	Vector2 position;
	Vector2 velocity;

	float velocityMag;

	float rotation;

	float dragForce;

	bool onRoad;

	//Style
	Color color;

	//Extern
	int checkPoint;
};

