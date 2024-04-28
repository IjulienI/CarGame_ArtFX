#pragma once
#include "scene.h"
#include "sceneManager.h"

#include "car.h"
#include "constant.h"
#include "tile.h"
#include "vector"
#include "filesystem"

class Game : public Scene {
public:
	Game();
	Game(int index);
	~Game();

	void Init() override;
	void Update(float dt) override;
	void Draw() override;
private:
	Tile* map[16][11];
	Car* player;

	std::vector<Tile*> obstacles;
	std::vector<Tile*> checkPoints;

	int mapIndex;
	int lap;

	float currentTime;
	int minutes;
	int seconds;
	int milliseconds;
};