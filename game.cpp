#include "game.h"

Game::Game() {
	this->player = new Car();
}

Game::~Game() {
}

void Game::Init() {
}

void Game::Update(float dt) {
	player->Update(dt);
}

void Game::Draw() {
	DrawCircle(500, 500, 15, WHITE);
	player->Draw();
}
