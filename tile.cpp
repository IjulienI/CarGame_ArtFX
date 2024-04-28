#include "tile.h"

Tile::Tile() {
	this->position = {0,0};
	this->texture = LoadTexture("textures/base.png");
	this->type = GRASS;
}

Tile::Tile(Vector2 position, Texture2D& texture) {
	this->position = position;
	this->texture = texture;
	this->type = GRASS;
}

Tile::Tile(Vector2 position) {
	this->position = position;
	this->texture = LoadTexture("textures/base.png");
	this->type = GRASS;
}

Tile::~Tile() {
	UnloadTexture(texture);
}

void Tile::SetType(TileType type) {
	this->type = type;
}

void Tile::SetTexture(Texture2D& texture) {
	this->texture = texture;
}

void Tile::Draw() {
	DrawTexture(texture, position.x, position.y, WHITE);
}

Vector2 Tile::GetPosition() {
	return position;
}

TileType Tile::GetType() {
	return type;
}
