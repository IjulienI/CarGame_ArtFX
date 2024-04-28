#pragma once
#include "constant.h"
#include "tileType.h"

class Tile {
public:
	Tile();
	Tile(Vector2 position, Texture2D& texture);
	Tile(Vector2 position);
	~Tile();

	void SetType(TileType type);
	void SetTexture(Texture2D& texture);
	void Draw();

	Vector2 GetPosition();
	TileType GetType();
private:
	Vector2 position;
	TileType type;
	Texture2D texture;
};

