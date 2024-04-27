#include "application.h"

Application* app = nullptr;

Application::Application()
{
	Init();	
}
Application::~Application()
{
}

void Application::Init()
{
	InitWindow(WINDOW_SIZE.x, WINDOW_SIZE.y, "NoEngine");
	SetTargetFPS(FRAME_LIMIT);

	debug = new Debug();
	car = new Car();

	while (!WindowShouldClose()) {
		Update();
		Draw();
	}

	CloseWindow();
}

void Application::Update()
{
	float deltaTime = GetFrameTime();
	debug->Update(deltaTime);
	car->Update(deltaTime);
}

void Application::Draw()
{
	BeginDrawing();
	ClearBackground(BACKGROUND_COLOR);
	debug->Draw();
	car->Draw();
	EndDrawing();
}
