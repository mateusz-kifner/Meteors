#include "Meteor.h"

Meteor::Meteor(std::string name, Texture2D sprite, float radius, Vector2 position, float rotation, float scale)
{
	this->sprite = sprite;
	this->position = position;
	this->radius = radius;
	this->rotation = rotation;
	this->scale = scale;
	this->velocity = Vector2Zero();
	this->direction = Vector2Rotate(Vector2{ 1, 0 }, rand()%360);
	this->speed = (rand() % 200)+10;
	this->current_rotation = (rand() % 30)/5.0;
	this->name = name;
	
}

void Meteor::update(float delta, int screenWidth, int screenHeight)
{
	
	this->velocity = this->direction * speed;
	this->move(this->velocity * delta);
	this->rotation += this->current_rotation;
}
