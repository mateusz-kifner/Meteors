#include "KinematicBody.h"

// static Definition
std::vector<KinematicBody*> KinematicBody::physicsBodies;


KinematicBody::KinematicBody(std::string name, Texture2D sprite, float radius, Vector2 position, float rotation, float scale)
{
	this->sprite = sprite;
	this->position = position;
	this->radius = radius;
	this->rotation = rotation;
	this->scale = scale;
	this->name = name;	
}

void KinematicBody::draw_debug()
{
	DrawCircleV(this->position, this->radius, RED);

}



void KinematicBody::draw(int screenWidth, int screenHeight)
{
	//DrawTextureEx(this->sprite, this->position - Vector2{(float)(this->sprite.width/2.0),(float)(this->sprite.height/2.0)}, this->rotation, this->scale, WHITE);
	DrawTexturePro(this->sprite,
		Rectangle {0, 0, (float)this->sprite.width, (float)this->sprite.height},
		Rectangle{ (float)this->position.x, (float)this->position.y, (float)(this->sprite.width), (float)(this->sprite.height) },
		Vector2{ (float)(this->sprite.width / 2), (float)(this->sprite.height / 2) }, this->rotation, WHITE);
}

void KinematicBody::move(Vector2 pos)
{
	this->position = pos + this->position;

}


void KinematicBody::resolveCollisions()
{
	for (auto& body : KinematicBody::physicsBodies)
	{
		std::cout << body->name << ", ";
	}
	std::cout << "--- collision resolved\n";
}

void KinematicBody::registerPhysicsBody(KinematicBody* body)
{
	KinematicBody::physicsBodies.push_back(body);
}

void KinematicBody::deletePhysicsBody(int id)
{
	KinematicBody::physicsBodies[id] = nullptr;
}

void KinematicBody::updateAll(float delta, int screenWidth, int screenHeight)
{
	for (auto& body : KinematicBody::physicsBodies)
	{
		body->update(delta, screenWidth, screenHeight);
	}
}
