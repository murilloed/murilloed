#include "raylib.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Exercicio 3");

    float posXAzul = 0.0f;
    float posXVermelho = (float)screenWidth;
    float velAzul = 2.0f;
    float velVermelho = 2.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        posXAzul += velAzul;
        posXVermelho -= velVermelho;

        velAzul += 0.01f;
        velVermelho += 0.01f;

        if (posXAzul > screenWidth) {
            posXAzul = -50.0f;
            velAzul = 2.0f;
        }
        if (posXVermelho < -50.0f) {
            posXVermelho = screenWidth;
            velVermelho = 2.0f;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle((int)posXAzul, 150, 50, 50, BLUE);
        DrawRectangle((int)posXVermelho, 250, 50, 50, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
