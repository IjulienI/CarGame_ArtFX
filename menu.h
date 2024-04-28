#pragma once
#include "scene.h"
#include "sceneManager.h"
#include <raylib.h>

class Menu : public Scene{
public:
	Menu();
	~Menu();

	void Init() override;
	void Update(float dt) override;
	void Draw() override;
};