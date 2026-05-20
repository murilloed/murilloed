#include "raylib.h"

int main()
{
    float posX = 0;
    float posY = 0;

    Texture2D feliz;

    InitWindow(800, 450, "Movimento Diagonal");

    feliz = LoadTexture("feliz.png");

    while (!WindowShouldClose())
    {
        posX += GetFrameTime() * 300;
        posY += GetFrameTime() * 100;

        if (posX > 800 || posY > 450)
        {
            posX = 0;
            posY = 0;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawTexture(feliz, posX, posY, WHITE);

        EndDrawing();
    }

    UnloadTexture(feliz);
    CloseWindow();

    return 0;
}