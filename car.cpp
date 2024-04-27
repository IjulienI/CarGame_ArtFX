#include "car.h"

Car::Car(){
	this->position = { 100,100 };
	this->velocity = {0,0};

	this->maxVelocity = 350;
	this->maxVelocityBack = maxVelocity / 2.0;
	this->acceleration = 150;
	this->velocityMag = 0;

	this->rotation = 0;
	this->rotationAcceleration = 1;

	this->dragForce = .2;
	this->baseDrag = dragForce;
	this->handBrakeDrag = 4;

	this->size = CAR_SIZE;
	this->color = WHITE;

	this->center = { size.x / 2,size.y / 2 };

	Init();
}

Car::Car(Vector2 position) {
	this->position = position;
	this->velocity = { 0,0 };

	this->maxVelocity = 350;
	this->maxVelocityBack = maxVelocity / 2.0;
	this->acceleration = 150;
	this->velocityMag = 0;

	this->rotation = 0;
	this->rotationAcceleration = 1;

	this->dragForce = .2;
	this->baseDrag = dragForce;
	this->handBrakeDrag = 4;

	this->size = CAR_SIZE;
	this->color = WHITE;

	this->center = { size.x / 2,size.y / 2 };

	Init();
}

Car::~Car(){
	//Destroy Texture
}

void Car::Init() {
	//Load Texture
}

void Car::Update(float dt)
{
	velocityMag = (velocity.x + velocity.y);
	
	/////////////////////////////////////////////
	//INPUTS
	/////////////////////////////////////////////

	//Movements
	if (IsKeyDown(KEY_W)) {
		if (velocityMag < maxVelocity) {
			velocity.x += acceleration * dt;
			velocity.y += acceleration * dt;
		}
	}
	if (IsKeyDown(KEY_S)) {
		if (velocityMag > -maxVelocityBack) {
			velocity.x -= acceleration * dt;
			velocity.y -= acceleration * dt;
		}
	}
	if (IsKeyDown(KEY_A)) {	
		if (velocityMag != 0) {
			rotation -= (rotationAcceleration / 1 * sqrtf(velocity.x * velocity.x + velocity.y * velocity.y)) * dt;
		}		
	}
	if (IsKeyDown(KEY_D)) {
		if (velocityMag != 0) {
			rotation += (rotationAcceleration / 1 * sqrtf(velocity.x * velocity.x + velocity.y * velocity.y)) * dt;
		}
	}

	//HandBrake
	if (IsKeyPressed(KEY_SPACE)) {
		dragForce = handBrakeDrag;
	}
	if (IsKeyReleased(KEY_SPACE)) {
		dragForce = baseDrag;
	}

	//Move
	Vector2 forward = { cos(rotation * (PI / 180.0)),sin(rotation * (PI / 180.0)) };
	position.x += forward.x * velocity.x * dt;
	position.y += forward.y * velocity.y * dt;

	//Drag
	velocity.x -= (dragForce / 1 * velocity.x) * dt;
	velocity.y -= (dragForce / 1 * velocity.y) * dt;
}

void Car::Draw()
{
	//Draw Car with rotation
	Rectangle car = { position.x,position.y,size.x,size.y };
	DrawRectanglePro(car,center, rotation, color);
}
