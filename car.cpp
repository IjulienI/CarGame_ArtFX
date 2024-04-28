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

	this->onRoad = true;

	this->color = RED;

	Init();
}

Car::Car(Vector2 position, float rotation, Color color) {
	this->position = position;
	this->velocity = { 0,0 };

	this->velocityMag = 0;

	this->rotation = rotation;

	this->dragForce = CAR_DRAG_FORCE;

	this->onRoad = true;

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
	this->dt = dt;
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
	forward = { (float)cos(rotation * (PI / 180.0)),(float)sin(rotation * (PI / 180.0)) };
	position.x += forward.x * velocity.x * dt;
	position.y += forward.y * velocity.y * dt;

	//Drag
	if (onRoad) {
		velocity.x -= (dragForce / 1 * velocity.x) * dt;
		velocity.y -= (dragForce / 1 * velocity.y) * dt;
	}
	else {
		velocity.x -= ((dragForce * 15) / 1 * velocity.x) * dt;
		velocity.y -= ((dragForce * 15) / 1 * velocity.y) * dt;
	}

	//Px/s to Km/h
	std::cout << (velocityMag / PIXELS_PER_METER) * 3.6 << std::endl;
}

void Car::Draw()
{
	//Draw Car with rotation
	Rectangle car = { position.x,position.y,CAR_SIZE.x,CAR_SIZE.y };
	DrawRectanglePro(car,CAR_CENTER, rotation, color);
}

bool Car::IsIn(Tile& tile) {
	if (CheckCollisionCircleRec({ position.x, position.y }, CAR_CIRCLE_COLLIDER, { tile.GetPosition().x,tile.GetPosition().y,TILE_SIZE,TILE_SIZE })) return true;
	return false;
}

void Car::SetOnRoad(bool onRoad) {
	this->onRoad = onRoad;
}

void Car::SetPosition(Vector2 position) {
	this->position = position;
}

Vector2 Car::GetPosition() {
	return position;
}

void Car::Impact() {
	velocity = { 0,0 };
	position.x -= forward.x * CAR_ACCELERATION * dt;
	position.y -= forward.y * CAR_ACCELERATION * dt;
}
