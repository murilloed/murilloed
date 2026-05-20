#include "raylib.h"

int main()
{
    int azulX = 0;
    int vermelhoX = 700;

    InitWindow(800, 450, "Dois Quadrados");

    while (!WindowShouldClose())
    {
        azulX++;
        vermelhoX--;

        if (azulX > 800)
        {
            azulX = 0;
        }

        if (vermelhoX < -100)
        {
            vermelhoX = 800;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(azulX, 100, 100, 100, BLUE);
        DrawRectangle(vermelhoX, 250, 100, 100, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}