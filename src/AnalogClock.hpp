#pragma once
#include "raylib.h"
 
class AnalogClock {

public:
    AnalogClock(int size, Vector2 position) : size(size), position(position), minute(0), hour(0), second(0) {};
    void Draw();
    void Update();

private:
    void DrawFace() const;
    void DrawHourMarks() const;
    void DrawHand(float handWidth, float handLength, int angle, Color color, int offset);
    void DrawMinuteHand(int minute);
    void DrawHourHand(int hour, int minute);
    void DrawSecondHand(int second);
    
    int size;
    Vector2 position;
    int minute;
    int hour;
    int second;
};