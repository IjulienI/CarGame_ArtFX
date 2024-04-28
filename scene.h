#pragma once

class Scene {
public:
	Scene();
	~Scene();
	virtual void Init();
	virtual void Update(float dt);
	virtual void Draw();
};