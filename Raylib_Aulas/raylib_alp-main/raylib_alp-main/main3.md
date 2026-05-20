#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Meu Jogo");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello World", 10, 10, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}