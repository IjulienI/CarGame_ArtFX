#include "car.h"

/*
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
   / \                                             / \    
  / | \        Toutes les variables utiles        / | \
 /  o  \          sont dans constant.h           /  o  \ 
 -------                                         -------
 /////////////////////////////////////////////////////////////
 /////////////////////////////////////////////////////////////
*/

Car::Car(){
	this->position = { 100,100 };
	this->velocity = {0,0};

	this->velocityMag = 0;

	this->rotation = 0;

	this->dragForce = CAR_DRAG_FORCE;

	this->color = WHITE;

	Init();
}

Car::Car(Vector2 position, float rotation, Color color) {
	this->position = position;
	this->velocity = { 0,0 };

	this->velocityMag = 0;

	this->rotation = rotation;

	this->dragForce = CAR_DRAG_FORCE;

	this->color = color;

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
		if (velocityMag < CAR_MAX_VELOCITY) {
			velocity.x += CAR_ACCELERATION * dt;
			velocity.y += CAR_ACCELERATION * dt;
		}
	}
	if (IsKeyDown(KEY_S)) {
		if (velocityMag > -CAR_MAX_BACK_VELOCITY) {
			velocity.x -= CAR_ACCELERATION * dt;
			velocity.y -= CAR_ACCELERATION * dt;
		}
	}
	if (IsKeyDown(KEY_A)) {	
		if (velocityMag > CAR_MIN_SPEED_ROTATION) {
			float rotationSpeed = CAR_ROTATION_ACCELERATION / sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);

			//Clamp RotationSpeed
			if (rotationSpeed > CAR_MAX_ROTATION_SPEED) {
				rotationSpeed = CAR_MAX_ROTATION_SPEED;

				rotation -= rotationSpeed * dt;
			}
			else rotation -= rotationSpeed * dt;
			//std::cout << rotationSpeed << std::endl;
		}		
	}
	if (IsKeyDown(KEY_D)) {
		if (velocityMag > CAR_MIN_SPEED_ROTATION) {
			float rotationSpeed = CAR_ROTATION_ACCELERATION / sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);

			//Clamp RotationSpeed
			if (rotationSpeed > CAR_MAX_ROTATION_SPEED) {
				rotationSpeed = CAR_MAX_ROTATION_SPEED;

				rotation += rotationSpeed * dt;
			}
			else rotation += rotationSpeed * dt;
			//std::cout << rotationSpeed << std::endl;
		}
	}

	//HandBrake
	if (IsKeyPressed(KEY_SPACE)) {
		dragForce = CAR_HANDBRAKE_DRAG;
	}
	if (IsKeyReleased(KEY_SPACE)) {
		dragForce = CAR_DRAG_FORCE;
	}

	//Move
	Vector2 forward = { cos(rotation * (PI / 180.0)),sin(rotation * (PI / 180.0)) };
	position.x += forward.x * velocity.x * dt;
	position.y += forward.y * velocity.y * dt;

	//Drag
	velocity.x -= (dragForce / 1 * velocity.x) * dt;
	velocity.y -= (dragForce / 1 * velocity.y) * dt;

	//Px/s to Km/h
	std::cout << (velocityMag / PIXELS_PER_METER) * 3.6 << std::endl;
}

void Car::Draw()
{
	//Draw Car with rotation
	Rectangle car = { position.x,position.y,CAR_SIZE.x,CAR_SIZE.y };
	DrawRectanglePro(car,CAR_CENTER, rotation, color);
}
