#pragma once
#include "raylib.h"
#include "raymathext.h"
#include <vector>
class KinematicBody
{ 
public:
	Vector2 position;
	float radius;
	float rotation;
	float scale;
	Texture2D sprite;
	std::string name;

	KinematicBody(){}
	KinematicBody(std::string name, Texture2D sprite, float radius, Vector2 position, float rotation = 0, float scale = 1);
	void draw_debug();
	virtual void update(float delta, int screenWidth, int screenHeight) {};
	virtual void draw(int screenWidth, int screenHeight);
	void move(Vector2 pos);

	static std::vector<KinematicBody*> physicsBodies;
	static void resolveCollisions();
	static void registerPhysicsBody(KinematicBody* body);
	static void deletePhysicsBody(int id);
	static void updateAll(float delta, int screenWidth, int screenHeight);
};





