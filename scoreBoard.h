#pragma once
#include "scene.h"
#include "sceneManager.h"
#include <raylib.h>
#include "raygui.h"

class ScoreBoard : public Scene {
public:
	ScoreBoard();
	~ScoreBoard();

	void Init() override;
	void Update(float dt) override;
	void Draw() override;
private:
};
