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
	void SetPosition(Vector2 position);
	Vector2 GetPosition();
	void Impact();
private:
	//Movements (base)
	Vector2 position;
	Vector2 velocity;
	Vector2 forward;

	float velocityMag;

	float rotation;

	float dragForce;

	bool onRoad;

	//Style
	Color color;

	//Extern
	int checkPoint;
	float dt;
};

