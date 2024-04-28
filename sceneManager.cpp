#include "sceneManager.h"

SceneManager* sceneManager = nullptr;

SceneManager::SceneManager() {
	this->currentScene = nullptr;
	Init();
}

SceneManager::~SceneManager() {
}

void SceneManager::Update(float dt) {
	currentScene->Update(dt);
}

void SceneManager::Draw() {
	currentScene->Draw();
}

void SceneManager::Init() {
	ChangeScene(MENU);
}

void SceneManager::ChangeScene(Scenes newScene) {
	if (currentScene != nullptr) {
		currentScene->~Scene();
	}
	switch (newScene)
	{
	case MENU:
		currentScene = new Menu();
		break;
	case LEVEL_SELECTION:
		currentScene = new LevelSelection();
		break;
	case GAME:
		currentScene = new Game();
		break;
	}
}

void SceneManager::LoadMap(int index) {
	currentScene = new Game(index);
}
