#include "raylib.h"

int main()
{
    Texture2D inimigo;
    Sound tiro;
    Sound acerto;
    Music musica;

    float inimigoX = -100;
    int pontos = 0;

    InitWindow(800, 450, "Mini Shooter");

    InitAudioDevice();

    inimigo = LoadTexture("inimigo.png");
    tiro = LoadSound("tiro.mp3");
    acerto = LoadSound("acerto.mp3");
    musica = LoadMusicStream("fundo.ogg");

    PlayMusicStream(musica);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(musica);

        inimigoX += GetFrameTime() * 300;

        if (inimigoX > 800)
        {
            inimigoX = -inimigo.width;
        }

        Rectangle areaInimigo = {
            inimigoX,
            100,
            inimigo.width,
            inimigo.height
        };

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            PlaySound(tiro);

            if (CheckCollisionPointRec(GetMousePosition(), areaInimigo))
            {
                PlaySound(acerto);
                pontos++;
                inimigoX = -inimigo.width;
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(inimigo, inimigoX, 100, WHITE);

        DrawText(TextFormat("Pontos: %d", pontos), 10, 10, 30, BLACK);
        DrawText("Clique no personagem para acertar", 220, 400, 20, DARKGRAY);

        EndDrawing();
    }

    UnloadTexture(inimigo);
    UnloadSound(tiro);
    UnloadSound(acerto);
    UnloadMusicStream(musica);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}