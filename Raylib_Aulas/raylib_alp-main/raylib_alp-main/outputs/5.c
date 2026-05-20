#include "raylib.h"

int main()
{
    Texture2D feliz;
    Texture2D inimigo;
    Texture2D luvaboxe;

    InitWindow(800, 450, "feliz");

    feliz = LoadTexture("feliz.png");
    inimigo = LoadTexture("inimigo.png");
    luvaboxe = LoadTexture("luvaboxe.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(feliz, 100, 150, WHITE);
        DrawTexture(inimigo, 350, 150, WHITE);
        DrawTexture(luvaboxe, 600, 150, WHITE);

        EndDrawing();
    }

    UnloadTexture(feliz);
    UnloadTexture(inimigo);
    UnloadTexture(luvaboxe);

    CloseWindow();

    return 0;
}