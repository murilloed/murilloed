#include "raylib.h"

int main()
{
    float lentoX = -100;
    float rapidoX = -100;

    Texture2D feliz;

    InitWindow(800, 450, "Velocidades Diferentes");

    feliz = LoadTexture("feliz.png");

    while (!WindowShouldClose())
    {
        lentoX += GetFrameTime() * 100;
        rapidoX += GetFrameTime() * 600;

        if (lentoX > 800)
        {
            lentoX = -100;
        }

        if (rapidoX > 800)
        {
            rapidoX = -100;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(feliz, lentoX, 100, WHITE);
        DrawTexture(feliz, rapidoX, 250, WHITE);

        EndDrawing();
    }

    UnloadTexture(feliz);
    CloseWindow();

    return 0;
}