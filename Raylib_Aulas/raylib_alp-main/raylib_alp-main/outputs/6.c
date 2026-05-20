#include "raylib.h"

int main()
{
    float posX = -100;
    Texture2D sprite;

    InitWindow(800, 450, "Delta Time");

    sprite = LoadTexture("sprite.png");

    while (!WindowShouldClose())
    {
        posX += GetFrameTime() * 300;

        if (posX > 800)
        {
            posX = -100;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(sprite, posX, 100, WHITE);
        DrawFPS(10, 10);

        EndDrawing();
    }

    UnloadTexture(sprite);
    CloseWindow();

    return 0;
}