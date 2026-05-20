#include "raylib.h"

int main()
{
    int posX = 0;
    int velocidade = 1;

    InitWindow(800, 450, "Acelerando");

    while (!WindowShouldClose())
    {
        posX += velocidade;
        velocidade++;

        if (posX > 800)
        {
            posX = 0;
            velocidade = 1;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawRectangle(posX, 180, 100, 100, BLUE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}