#include "raylib.h"

int main()
{
    float posX = -100; // posição inicial (fora da tela)

    Texture2D sprite;

    Sound sound; // variável de som

    InitWindow(800, 450, "basic window");

    InitAudioDevice(); // inicia o sistema de áudio

    sprite = LoadTexture("sprite.png");

    sound = LoadSound("sound.ogg"); // carrega o som

    while (!WindowShouldClose())
    {
        posX += GetFrameTime() * 300;

        // quando sair da tela, toca som
        if (posX > 800)
        {
            posX = -100;

            PlaySound(sound);
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(sprite, posX, 10, WHITE);

        EndDrawing();
    }

    UnloadSound(sound);

    CloseAudioDevice();

    CloseWindow();

    return 0;
}