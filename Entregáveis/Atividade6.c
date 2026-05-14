#include "raylib.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Exercicio 6");
    
    Texture2D figuraLenta = LoadTexture("assets/lenta.png");
    Texture2D figuraRapida = LoadTexture("assets/rapida.png");
    Texture2D figuraDiagonal = LoadTexture("assets/diagonal.png");

    float posX_Lenta = 0.0f;
    float posX_Rapida = 0.0f;
    float posX_Diag = 0.0f;
    float posY_Diag = 0.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        float deltaTime = GetFrameTime();

        posX_Lenta += 100.0f * deltaTime;
        posX_Rapida += 600.0f * deltaTime;
        
        posX_Diag += 300.0f * deltaTime;
        posY_Diag += 100.0f * deltaTime;

        if (posX_Lenta > screenWidth) posX_Lenta = 0.0f;
        if (posX_Rapida > screenWidth) posX_Rapida = 0.0f;
        if (posX_Diag > screenWidth) posX_Diag = 0.0f;
        if (posY_Diag > screenHeight) posY_Diag = 0.0f;

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(figuraLenta, (int)posX_Lenta, 50, WHITE);
        DrawTexture(figuraRapida, (int)posX_Rapida, 150, WHITE);
        DrawTexture(figuraDiagonal, (int)posX_Diag, (int)posY_Diag, WHITE);

        EndDrawing();
    }

    UnloadTexture(figuraLenta);
    UnloadTexture(figuraRapida);
    UnloadTexture(figuraDiagonal);

    CloseWindow();

    return 0;
}
