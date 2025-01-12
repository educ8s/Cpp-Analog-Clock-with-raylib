#pragma once
#include <raylib.h>
#include <ctime>

class AnalogClock {

    public:
        AnalogClock(int size, Vector2 position) :size(size), position(position), hour(0), minute(0), second(0) {};
        void Draw() const;
        void Update();
    private:
        void DrawFace() const;
        void DrawHourMarks() const;
        void DrawMinuteHand(int minute) const;
        void DrawHand(float handWidth, float handLength, int angle, Color color, int offset) const;
        void DrawHourHand(int hour, int minute) const;
        void DrawSecondHand(int second) const;
        int size;
        Vector2 position;
        int hour;
        int minute;
        int second;
};