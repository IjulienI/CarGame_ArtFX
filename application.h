#pragma once
#include "constant.h"
#include "debug.h"
#include "car.h"

class Application
{
public:
	Application();
	~Application();
private:
	void Init();
	void Update();
	void Draw();

	Car* car;
};

extern Application* app;