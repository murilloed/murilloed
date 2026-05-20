#include "raylib.h"

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "Desafio Raylib - Construindo Formas");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawRectangle(100, 100, 50, 50, RED);

    DrawRectangle(300, 150, 200, 100, GREEN);

    DrawRectangle(600, 300, 80, 80, YELLOW);

    DrawText("Shapes rendering complete.", 10, 10, 20, DARKGRAY);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}