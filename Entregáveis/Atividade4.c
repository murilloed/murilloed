#include "raylib.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Exercicio 4");

    SetTargetFPS(60);

    int posX = 0;

    while (!WindowShouldClose()) {
        posX += 5;

        if (posX > screenWidth) {
            posX = -50;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(posX, 200, 50, 50, RED);
        
        DrawFPS(10, 10);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
