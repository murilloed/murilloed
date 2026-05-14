#include "raylib.h"

int main()
{
    float posX = -100; // posição do sprite (começa fora da tela à esquerda)

    Texture2D sprite;

    InitWindow(800, 450, "basic window");

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

        DrawTexture(sprite, posX, 10, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}