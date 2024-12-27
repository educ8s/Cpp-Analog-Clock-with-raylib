#include "AnalogClock.hpp"
#include <ctime>

const Color DARK_GREY = {45, 45, 45 , 255};
const Color LIGHT_GREY = {229, 229, 229, 255};

void AnalogClock::Draw()
{
    DrawFace();
    DrawHourMarks();
    DrawMinuteHand(minute);
    DrawHourHand(hour, minute);
    DrawSecondHand(second);
    DrawCircle(position.x, position.y, 15, DARK_GREY);
}

void AnalogClock::Update()
{
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    minute = now -> tm_min;
    hour = now -> tm_hour % 12;
    second = now -> tm_sec;
}

void AnalogClock::DrawFace() const
{
    DrawCircle(position.x, position.y, size, DARK_GREY);
    DrawCircle(position.x, position.y, size - 30, LIGHT_GREY);
    DrawCircle(position.x, position.y, size - 40, RAYWHITE);
}

void AnalogClock::DrawHourMarks() const
{
    float rectWidth = 10;
    float rectHeight = size;

    float rect_x = position.x ;
    float rect_y = position.y ;

    Rectangle rect = {rect_x, rect_y, rectWidth, rectHeight};
    for(int i = 0; i < 12 ; i++)
    {
        DrawRectanglePro(rect, {rectWidth / 2, rectHeight}, i*30, DARK_GREY);
    }
    
    DrawCircle(position.x, position.y, size - 50, RAYWHITE);
}

void AnalogClock::DrawHand(float handWidth, float handLength, int angle, Color color, int offset)
{
    float hand_x = position.x;
    float hand_y = position.y;
    
    Rectangle handRect = Rectangle{hand_x, hand_y, handWidth, handLength};
    DrawRectanglePro(handRect, {handWidth/2, handLength - offset}, angle, color);
}

void AnalogClock::DrawMinuteHand(int minute) 
{
    int angle = minute * 6;
    DrawHand(10, size*0.7, angle, DARK_GREY, 0);
}

void AnalogClock::DrawHourHand(int hour, int minute)
{
    int angle = 30 * hour + (minute/60) * 30;
    DrawHand(15, size*0.6, angle, DARK_GREY, 0);
}

void AnalogClock::DrawSecondHand(int second)
{
     int angle = second * 6;
     DrawHand(5, size*1.05, angle, RED, 55);
}