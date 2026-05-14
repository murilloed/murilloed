#include "raylib.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Exercicio 5");

    Texture2D personagem = LoadTexture("personagem.png");
    Texture2D inimigo = LoadTexture("inimigo.png");
    Texture2D item = LoadTexture("item.png");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(personagem, 100, 100, BLUE);
        DrawTexture(inimigo, 300, 150, RED);
        DrawTexture(item, 500, 200, GREEN);

        EndDrawing();
    }

    UnloadTexture(personagem);
    UnloadTexture(inimigo);
    UnloadTexture(item);

    CloseWindow();

    return 0;
}
