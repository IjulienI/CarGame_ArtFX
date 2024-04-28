#include "game.h"

Game::Game() {	
	this->mapIndex = 0;
	this->lap = 0;
	Init();
}

Game::Game(int index) {
	this->mapIndex = index;
	this->lap = 0;
	Init();
}

Game::~Game() {
	delete player;
	for (int i = 0; i < TILE_NUM.x; i++) {
		for (int j = 0; j < TILE_NUM.y; j++) {
			map[i][j]->~Tile();
		}
	}
}

void Game::Init() {
	Texture2D road = LoadTexture("textures/road.png");
	Texture2D grass = LoadTexture("textures/grass.png");
	Texture2D finish = LoadTexture("textures/finish.png");
	Texture2D obstacle = LoadTexture("textures/obstacle.png");
	Image mapImage = LoadImage("textures/base.png");

	std::string path = "textures/maps";

	int index = 0;
	for (const auto& entry : std::filesystem::directory_iterator(path)) {
		if (entry.path().extension() == ".png") {
			std::string filePath = entry.path().string();			
			if (index == mapIndex) {
				UnloadImage(mapImage);
				mapImage = LoadImage(filePath.c_str());
			}
			index++;
		}
	}
	Color* pixels = LoadImageColors(mapImage);

	int pixelIndex = 0;
	for (int i = 0; i < TILE_NUM.x; i++) {
		for (int j = 0; j < TILE_NUM.y; j++) {
			map[i][j] = new Tile({ (i * TILE_SIZE) + TILE_SPACER.x, (j * TILE_SIZE) + TILE_SPACER.y });
			if (pixels[j * mapImage.width + i].r == 0 && pixels[j * mapImage.width + i].g == 0 && pixels[j * mapImage.width + i].b == 0) {
				map[i][j]->SetTexture(road);
				map[i][j]->SetType(ROAD);
			}
			else if (pixels[j * mapImage.width + i].r == 0 && pixels[j * mapImage.width + i].g == 255 && pixels[j * mapImage.width + i].b == 21) {
				map[i][j]->SetTexture(grass);
				map[i][j]->SetType(GRASS);
			}
			else if (pixels[j * mapImage.width + i].r == 255 && pixels[j * mapImage.width + i].g == 0 && pixels[j * mapImage.width + i].b == 0) {
				map[i][j]->SetTexture(obstacle);
				map[i][j]->SetType(OBSTACLE);
				obstacles.push_back(map[i][j]);
			}
			else if (pixels[j * mapImage.width + i].r == 255 && pixels[j * mapImage.width + i].g == 255 && pixels[j * mapImage.width + i].b == 255) {
				map[i][j]->SetTexture(finish);
				map[i][j]->SetType(FINISH);
				this->player = new Car();
				player->SetPosition(map[i][j]->GetCenter());
			}
			else if (pixels[j * mapImage.width + i].r == 0 && pixels[j * mapImage.width + i].g == 0 && pixels[j * mapImage.width + i].b == 255) {
				map[i][j]->SetTexture(road);
				map[i][j]->SetType(CHECKPOINTS);
				checkPoints.push_back(map[i][j]);
			}
			pixelIndex++;
		}
	}
	UnloadImage(mapImage);
	UnloadImageColors(pixels);
}

void Game::Update(float dt) {
	player->Update(dt);

	for (int i = 0; i < TILE_NUM.x; i++) {
		for (int j = 0; j < TILE_NUM.y; j++) {
			if (player->IsIn(*map[i][j]) && map[i][j]->GetType() == ROAD) {
				player->SetOnRoad(true);
			}
			else if (player->IsIn(*map[i][j]) && map[i][j]->GetType() == FINISH) {
				player->SetOnRoad(true);
				int activatedCheckpoints = 0;
				for (int i = 0; i < checkPoints.size(); i++) {
					if (checkPoints[i]->GetActivated()) {
						activatedCheckpoints++;
					}
				}
				if (activatedCheckpoints == checkPoints.size()) {
					lap++;
					if (lap == GAME_MAX_LAP) {
						sceneManager->ChangeScene(MENU);
					}
					for (int i = 0; i < checkPoints.size(); i++) {
						checkPoints[i]->SetActivated(false);
					}
				}
			}
			else if (player->IsIn(*map[i][j]) && map[i][j]->GetType() == CHECKPOINTS) {
				player->SetOnRoad(true);
				map[i][j]->SetActivated(true);
			}
			else if (player->IsIn(*map[i][j]) && map[i][j]->GetType() == GRASS) {
				player->SetOnRoad(false);
			}
		}
	}
	for (int i = 0; i < obstacles.size(); i++) {
		//C'est pas beau, j'avais autre chose en tete mais j'ai perdu mon temps sur d'autres problèmes
		if (CheckCollisionCircleRec(player->GetPosition(), CAR_CIRCLE_COLLIDER, { obstacles[i]->GetPosition().x,obstacles[i]->GetPosition().y,TILE_SIZE,TILE_SIZE })) {
			player->Impact();
		}
	}

	currentTime += 1 * dt;
	minutes = (int)(currentTime / 60);
	seconds = (int)(currentTime) % 60;
	milliseconds = (int)(currentTime * 1000) % 1000;
}

void Game::Draw() {	
	for (int i = 0; i < TILE_NUM.x; i++) {
		for (int j = 0; j < TILE_NUM.y; j++) {
			map[i][j]->Draw();
		}
	}
	player->Draw();
	DrawText(TextFormat("LAP : %i/%i", lap, GAME_MAX_LAP), 35, 10, 32, PURPLE);
	DrawText(TextFormat("%02i:%02i:%03i", minutes, seconds, milliseconds), 35, 47, 28, WHITE);
}
