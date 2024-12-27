#include "raylib.h"
#include "AnalogClock.hpp"

int main() {
    const int screenWidth = 600;
    const int screenHeight = 600;
    const Color LIGHT_BLUE = {225, 239, 240, 255};
    
    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_TRANSPARENT);

    InitWindow(screenWidth, screenHeight, "raylib Analog Clock");
    AnalogClock analogClock = {250, {300, 300}};
    SetTargetFPS(15);

    while (!WindowShouldClose()) {

        analogClock.Update();

        BeginDrawing();
            ClearBackground(LIGHT_BLUE);
            analogClock.Draw();
        EndDrawing();
    }

    CloseWindow();
}