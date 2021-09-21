#include <iostream>
#include "raylib.h"
#include "KinematicBody.h"
#include "Player.h"
#include "Meteor.h"
#include <time.h>
#include <random>
#include <string>
#include <array>


bool kinematicBodyColision(KinematicBody k1, KinematicBody k2) {
    float dist = Vector2Distance(k1.position, k2.position);
    if (dist < k1.radius + k2.radius) {
        return true;
    }
    return false;
}
int main(void)
{

    // Window Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "Meteors");
    SetTargetFPS(60); 
    srand(time(NULL));
    const Vector2 center = Vector2{ screenWidth / 2, screenHeight / 2 };
    //--------------------------------------------------------------------------------------
    // Initialization
    Texture2D meteor = LoadTexture("assets/meteor01.png"); // Load texture from file into GPU memory (VRAM)
    Texture2D spaceship = LoadTexture("assets/spaceship.png"); // Load texture from file into GPU memory (VRAM)
    Texture2D stars = LoadTexture("assets/stars.png"); // Load texture from file into GPU memory (VRAM)
    //Meteor k1 = Meteor("meteor", meteor, 50, V/ector2{ 100, 100 });
    Player player = Player("player", spaceship, 50, Vector2{ 200, 200 });

    //KinematicBody::registerPhysicsBody(&k1);
    KinematicBody::registerPhysicsBody(&player);


    float size = 410;

    std::array<Meteor, 20> meteors;
    for (int a = 0; a < 20; a++) {
        float alfa = (a/20.0)*2.0*PI;
        meteors[a] = (Meteor("meteor" + std::to_string(a), meteor, 50, Vector2{cos(alfa)*size, sin(alfa)*size}+center));
        KinematicBody::registerPhysicsBody(&(meteors[a]));
    }




    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //player.update(GetFrameTime(), screenWidth, screenHeight);
        KinematicBody::updateAll(GetFrameTime(), screenWidth, screenHeight);
        //k1.update(GetFrameTime());
        KinematicBody::resolveCollisions();
        /*for (auto& m : meteors) {
            m.update(GetFrameTime());
        }*/
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTextureV(stars, Vector2Zero(), WHITE);
        for (auto& m : meteors) {
            m.draw(screenWidth, screenHeight);
        }
        //k1.draw();
        player.draw_debug();
        player.draw(screenWidth, screenHeight);
        
       

        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

