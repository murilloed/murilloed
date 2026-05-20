#include "raylib.h"

int main()
{
    Texture2D inimigo;
    Sound tiro;
    Sound acerto;
    Music musica;

    float inimigoX = -100;
    float inimigoY = 150;
    float velocidade = 300;

    int pontos = 0;
    int vidas = 3;

    InitWindow(800, 450, "Mini Shooter Completo");

    InitAudioDevice();

    inimigo = LoadTexture("feliz.png");
    tiro = LoadSound("tiro.mp3");
    acerto = LoadSound("acerto.ogg");
    musica = LoadMusicStream("fundo.ogg");

    PlayMusicStream(musica);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(musica);

        if (vidas > 0)
        {
            inimigoX += GetFrameTime() * velocidade;

            if (inimigoX > 800)
            {
                inimigoX = -inimigo.width;
                vidas--;
            }

            Rectangle areaInimigo = {
                inimigoX,
                inimigoY,
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
                    velocidade += 30;
                    inimigoX = -inimigo.width;
                }
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        if (vidas > 0)
        {
            DrawTexture(inimigo, inimigoX, inimigoY, WHITE);

            DrawText(TextFormat("Pontos: %d", pontos), 10, 10, 25, BLACK);
            DrawText(TextFormat("Vidas: %d", vidas), 10, 40, 25, RED);
            DrawText("Clique no alvo antes que ele saia da tela!", 180, 400, 20, DARKGRAY);
        }
        else
        {
            DrawText("GAME OVER", 280, 180, 50, RED);
            DrawText(TextFormat("Pontuacao final: %d", pontos), 280, 250, 25, BLACK);
        }

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