#include "raylib.h"

int main()
{
    Texture2D sprite;   // Vou ter uma imagem chamada sprite

    InitWindow(800, 450, "basic window");

    sprite = LoadTexture("sprite.png");   // Carregue a imagem sprite.png para usar no jogo

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(sprite, 10, 10, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}