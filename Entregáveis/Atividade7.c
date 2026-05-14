#include "raylib.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Exercicio 7");

    InitAudioDevice();

    Sound tiro = LoadSound("assets/tiro.mp3");
    Sound explosao = LoadSound("assets/explosao.mp3");
    Sound moeda = LoadSound("assets/moeda.mp3");
    Music musica = LoadMusicStream("assets/fundo.mp3");

    PlayMusicStream(musica);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        UpdateMusicStream(musica);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            PlaySound(tiro);
        }
        
        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
            PlaySound(explosao);
        }
        
        if (IsKeyPressed(KEY_SPACE)) {
            PlaySound(moeda);
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Esquerdo: Tiro | Direito: Explosao | Espaco: Moeda", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    UnloadSound(tiro);
    UnloadSound(explosao);
    UnloadSound(moeda);
    UnloadMusicStream(musica);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}
