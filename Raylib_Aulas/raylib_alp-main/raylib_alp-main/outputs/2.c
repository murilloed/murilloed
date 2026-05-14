#include "raylib.h"

int main()
{
    InitWindow(800, 450, "Formas com Raylib");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(100, 100, 100, 100, RED);
        DrawRectangle(250, 100, 200, 80, GREEN);
        DrawRectangle(500, 100, 100, 100, YELLOW);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}