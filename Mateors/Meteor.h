#pragma once
#include "KinematicBody.h"
#include "raylib.h"
class Meteor :
    public KinematicBody
{
public:
    float current_rotation;
    float speed;
    Vector2 velocity;
    Vector2 direction;
    Meteor(std::string name, Texture2D sprite, float radius, Vector2 position, float rotation = 0, float scale = 1);
    Meteor() {}
    void update(float delta, int screenWidth, int screenHeight);
};

