#pragma once
#include "KinematicBody.h"
#include "raylib.h"
class Player :
    public KinematicBody
{
public:

    Vector2 velocity;
    Vector2 direction;
    Player(std::string name, Texture2D sprite, float radius, Vector2 position, float rotation = 0, float scale = 1);
    void update(float delta, int screenWidth, int screenHeight);
    void draw(int screenWidth, int screenHeight);
};


