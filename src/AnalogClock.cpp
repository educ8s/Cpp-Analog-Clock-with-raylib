#include "AnalogClock.hpp"

Color DARK_GREY = {45, 45, 45, 255};
Color LIGHT_GREY = {229, 229, 229, 255};

void AnalogClock::Draw() const
{
    DrawFace();
    DrawHourMarks();
    DrawMinuteHand(minute);
    DrawHourHand(hour, minute);
    DrawSecondHand(second);
    DrawCircleV(position, 15, DARK_GREY);
}

void AnalogClock::Update()
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    hour = now -> tm_hour % 12;
    minute = now -> tm_min;
    second = now -> tm_sec;
}

void AnalogClock::DrawFace() const
{
    DrawCircleV(position, size, DARK_GREY);
    DrawCircleV(position, size - 30, LIGHT_GREY);
    DrawCircleV(position, size - 40, RAYWHITE);
}

void AnalogClock::DrawHourMarks() const
{
    float rectWidth = 10;
    float rectHeight = size;

    Rectangle rect = {position.x, position.y, rectWidth, rectHeight};
    for(int i =0; i<12; i++)
    {
        DrawRectanglePro(rect, {rectWidth/2, rectHeight}, i*30, DARK_GREY);
    }
    DrawCircleV(position, size - 50, RAYWHITE);
}

void AnalogClock::DrawMinuteHand(int minute) const
{
    float handWidth = 10;
    float handLength = size * 0.7;
    int angle = minute * 6;

    DrawHand(handWidth, handLength, angle, DARK_GREY, 0);
}

void AnalogClock::DrawHand(float handWidth, float handLength, int angle, Color color, int offset) const
{
    Rectangle handRect = Rectangle{position.x, position.y, handWidth, handLength};
    DrawRectanglePro(handRect, {handWidth/2, handLength - offset}, angle, color);
}

void AnalogClock::DrawHourHand(int hour, int minute) const
{
    float handWidth = 15;
    float handLength = size * 0.6;
    int angle = 30 * hour + (minute / 60.0) * 30;
    DrawHand(handWidth, handLength, angle, DARK_GREY, 0);
}

void AnalogClock::DrawSecondHand(int second) const
{
    float handWidth = 5;
    float handLength = size * 1.05;
    int angle = second * 6;
    DrawHand(handWidth, handLength, angle, RED, 55);
}
