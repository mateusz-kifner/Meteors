#include "Player.h"
#include <math.h>


#define PI 3.14159265

Player::Player(std::string name, Texture2D sprite, float radius, Vector2 position, float rotation, float scale)
{
	this->sprite = sprite;
	this->position = position;
	this->radius = radius;
	this->rotation = rotation;
	this->scale = scale;
	this->velocity = Vector2Zero();
	this->direction = Vector2{ 1, 0 };
	this->name = name;
}

void Player::update(float delta, int screenWidth, int screenHeight)
{
	float current_rotation = 0;
	if (IsKeyDown(KEY_RIGHT)) current_rotation += 50.0f*delta;
	else if (IsKeyDown(KEY_LEFT)) current_rotation -= 50.0f*delta;
	this->direction = Vector2Rotate(this->direction, current_rotation);
	float speed = 0;


	if (IsKeyDown(KEY_UP)) speed += 100.0f;
	else if (IsKeyDown(KEY_DOWN)) speed -= 100.0f;
	/*else {
		this->velocity.y = this->velocity.y *0.99;
		if (this->velocity.y < 1 && this->velocity.y > -1) {
			this->velocity.y = 0;
		}
	}*/
	this->velocity = this->direction * speed;
	this->move(this->velocity * delta);
	this->rotation = atan2(this->direction.y, this->direction.x)*(180.0/PI)+90;

	if (this->position.x < 0) {
		this->position.x = screenWidth;
	}
	if (this->position.x > screenWidth) {
		this->position.x = 0;
	}

	if (this->position.y < 0) {
		this->position.y = screenHeight;
	}
	if (this->position.y > screenHeight) {
		this->position.y = 0;
	}
}
void Player::draw(int screenWidth, int screenHeight)
{
	//DrawTextureEx(this->sprite, this->position - Vector2{(float)(this->sprite.width/2.0),(float)(this->sprite.height/2.0)}, this->rotation, this->scale, WHITE);
	DrawTexturePro(this->sprite,
		Rectangle {0, 0, (float)this->sprite.width, (float)this->sprite.height},
		Rectangle{ (float)this->position.x, (float)this->position.y, (float)(this->sprite.width), (float)(this->sprite.height) },
		Vector2{ (float)(this->sprite.width / 2), (float)(this->sprite.height / 2) }, this->rotation, WHITE);

	DrawTexturePro(this->sprite,
		Rectangle {0, 0, (float)this->sprite.width, (float)this->sprite.height},
		Rectangle{ (float)this->position.x+screenWidth, (float)this->position.y, (float)(this->sprite.width), (float)(this->sprite.height) },
		Vector2{ (float)(this->sprite.width / 2), (float)(this->sprite.height / 2) }, this->rotation, WHITE);

	DrawTexturePro(this->sprite,
		Rectangle {0, 0, (float)this->sprite.width, (float)this->sprite.height},
		Rectangle{ (float)this->position.x - screenWidth, (float)this->position.y, (float)(this->sprite.width), (float)(this->sprite.height) },
		Vector2{ (float)(this->sprite.width / 2), (float)(this->sprite.height / 2) }, this->rotation, WHITE);

	DrawTexturePro(this->sprite,
		Rectangle {0, 0, (float)this->sprite.width, (float)this->sprite.height},
		Rectangle{ (float)this->position.x, (float)this->position.y + screenHeight, (float)(this->sprite.width), (float)(this->sprite.height) },
		Vector2{ (float)(this->sprite.width / 2), (float)(this->sprite.height / 2) }, this->rotation, WHITE);

	DrawTexturePro(this->sprite,
		Rectangle {0, 0, (float)this->sprite.width, (float)this->sprite.height},
		Rectangle{ (float)this->position.x, (float)this->position.y - screenHeight, (float)(this->sprite.width), (float)(this->sprite.height) },
		Vector2{ (float)(this->sprite.width / 2), (float)(this->sprite.height / 2) }, this->rotation, WHITE);
		
}
