#include "raylib.h"

int main() {
  InitWindow(800, 600, "My first game");

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Wellcome to raylib", 10, 10, 40, BLUE);

    DrawText("Press esc to exit", 10, 60, 10, RED);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}