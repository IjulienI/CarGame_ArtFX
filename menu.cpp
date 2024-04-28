#include "menu.h"

Menu::Menu() {
}

Menu::~Menu() {
}

void Menu::Init() {
}

void Menu::Update(float dt) {
	if (IsKeyPressed(KEY_E)) {
		sceneManager->ChangeScene(GAME);
	}
}

void Menu::Draw() {
}
