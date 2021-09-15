#include <iostream>
#include "raylib.h"
#include "raymath.h"


int main(void)
{
    // Window Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "Meteors");
    SetTargetFPS(60); 
    //--------------------------------------------------------------------------------------
    // Initialization

    Texture2D meteor = LoadTexture("assets/meteor01.png"); // Load texture from file into GPU memory (VRAM)
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        
            Texture2D tex;
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawTextureV(meteor, Vector2{ 100,100 }, WHITE);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

