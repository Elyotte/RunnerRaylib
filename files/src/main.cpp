#include "raylib.h"
#include "GraphicObject.h"
#include "Paralax.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - background scrolling");


    Texture2D background = LoadTexture("resources/cyberpunk_street_background.png");
    background.height = screenHeight;
    background.width = screenWidth;
    //Texture2D midground = LoadTexture("resources/cyberpunk_street_midground.png");
    //Texture2D foreground = LoadTexture("resources/cyberpunk_street_foreground.png");

    float scrollingBack = 0.0f;
    float scrollingMid = 0.0f;
    float scrollingFore = 0.0f;
    Texture baseTexture = LoadTexture("resources/icons.png");

    Paralax paralax = Paralax();
    paralax.texture = LoadTexture("resources/yoshiBackground.png");
    paralax.texture.height = screenHeight;
    paralax.texture.width = screenWidth;
    paralax.paralaxSpeed = 5.0f;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        scrollingBack -= 3.0f;

        // NOTE: Texture is scaled twice its size, so it sould be considered on scrolling
        if (scrollingBack <= -background.width * 2) scrollingBack = 0;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        paralax.Update();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(background);  // Unload background texture

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}