#pragma once
#include "scene.h"
#include "sceneManager.h"
#include <raylib.h>

#include "car.h"

class Game : public Scene {
public:
	Game();
	~Game();

	void Init() override;
	void Update(float dt) override;
	void Draw() override;
private:
	Car* player;
};