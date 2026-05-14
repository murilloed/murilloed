#include "raylib.h"

int main()
{
    int posX = 0;

    InitWindow(800, 450, "Teste de FPS");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        posX++;

        if (posX > 800)
        {
            posX = 0;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(posX, 100, 100, 100, BLUE);
        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}