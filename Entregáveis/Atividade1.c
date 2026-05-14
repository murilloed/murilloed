#include "raylib.h"

int main() {
  InitWindow(800, 600, "My First Game");

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("Welcome to My First Game", 10, 10, 40, BLUE);

    DrawText("Press " ESC " to exit", 10, 60, 20, RED)

        EndDrawing();
  }

  CloseWindow();

  return 0;
}