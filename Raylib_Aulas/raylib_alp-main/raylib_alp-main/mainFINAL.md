#include <stdio.h>
#include "raylib.h"

int main()
{
    Texture2D sprite;
    Sound sound;
    Music music;
    
    InitWindow(800, 450, "basic window");
    
    InitAudioDevice();
    
    sprite = LoadTexture("feliz.png");   // 🖼️ alterado
    sound = LoadSound("tiro.mp3");       // 🔊 alterado
    music = LoadMusicStream("fundo.ogg"); // 🎵 alterado
    
    float posX = -sprite.width;
    
    PlayMusicStream(music); //  importante: iniciar música
    
    while(!WindowShouldClose())
    {
        UpdateMusicStream(music);
        
        posX += GetFrameTime() * 300;
        if (posX > 800)
        {
            posX = -sprite.width;
        }
        
        if (IsKeyPressed(KEY_SPACE))
        {
            StopMusicStream(music);
            PlayMusicStream(music);
        }
        
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            Rectangle spriteRect = {
                posX,
                10,
                sprite.width,
                sprite.height
            };
            
            if (CheckCollisionPointRec(GetMousePosition(), spriteRect))
            {
                PlaySound(sound);
            }
        }
        
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            
            DrawTexture(sprite, posX, 10, WHITE);
            // DrawCircle(posX, 10, 5, GREEN);	
            
        EndDrawing();
    }
    
    StopMusicStream(music);
    
    UnloadTexture(sprite);   //  boa prática
    UnloadSound(sound);      //  boa prática
    UnloadMusicStream(music);//  boa prática
    
    CloseAudioDevice();
    
    CloseWindow();
    
    return 0;
}