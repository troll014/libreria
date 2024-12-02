#include"ultrasonic.h"
#include"Arduino.h"

void ultrasonic::Init()
{
    pinMode(Trig_PIN, OUTPUT);
    pinMode(Echo_PIN, INPUT);
}

float ultrasonic::Ranging(int Trig, int Echo) 
{
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);
    float distance = pulseIn(Echo, HIGH) / 58.00;
    delay(10); 
    return distance;
}