#include "raylib.h"

int main()
{
    int posX = 0;

    InitWindow(800, 450, "basic window");

    SetTargetFPS(24);  // Diz ao Raylib quantas vezes por segundo o loop do jogo deve rodar

    while (!WindowShouldClose())
    {
        posX++;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(posX, 100, 100, 100, BLUE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}