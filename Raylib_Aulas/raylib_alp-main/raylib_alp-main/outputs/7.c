#include "raylib.h"

int main()
{
    Sound tiro;
    Sound explosao;
    Music musica;

    InitWindow(800, 450, "Audio");

    InitAudioDevice();

    tiro = LoadSound("tiro.mp3");
    explosao = LoadSound("explosao.mp3");
    musica = LoadMusicStream("fundo.ogg");

    PlayMusicStream(musica);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(musica);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySound(tiro);
        }

        if (IsKeyPressed(KEY_SPACE))
        {
            PlaySound(explosao);
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Clique com o mouse para atirar", 180, 180, 25, BLACK);
        DrawText("Aperte ESPACO para explosao", 180, 220, 25, RED);

        EndDrawing();
    }

    UnloadSound(tiro);
    UnloadSound(explosao);
    UnloadMusicStream(musica);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}