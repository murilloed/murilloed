#include "raylib.h"

int main()
{
    InitWindow(800, 450, "Casinha");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(300, 200, 200, 150, BROWN);
        DrawTriangle(
            (Vector2){280, 200},
            (Vector2){520, 200},
            (Vector2){400, 100},
            RED
        );
        DrawRectangle(370, 270, 60, 80, DARKBROWN);
        DrawRectangle(320, 230, 40, 40, SKYBLUE);
        DrawRectangle(440, 230, 40, 40, SKYBLUE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}