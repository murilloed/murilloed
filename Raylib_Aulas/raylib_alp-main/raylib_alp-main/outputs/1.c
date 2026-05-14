#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Meu Primeiro Game");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Bem-vindo ao Raylib", 180, 250, 40, BLUE);
        DrawText("Pressione ESC para sair", 250, 320, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}