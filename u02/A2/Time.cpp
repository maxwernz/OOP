#include "Time.h"

Time::Time(int hour, int minute, int second) : m_hour(hour), m_minute(minute), m_second(second) 
{
    m_justseconds = hour * 3600 + minute * 60 + second;
}

int Time::diff(Time a, Time b)
{
    return a.justseconds() - b.justseconds();
}

void Time::update()
{
    int jsecs = justseconds();
    
    m_hour = jsecs / 3600;
    int hr = jsecs % 3600;
    m_minute = hr / 60;
    int mr = hr % 60;
    m_second = mr;
    
    if (jsecs < 0)
    {
        m_hour = m_minute = m_second = 0;
    }
}

void Time::add(Time a)
{
    m_hour += a.hour();
    m_minute += a.minute();
    m_second += a.second();
    update();
}

void Time::addHours(int hours)
{
    m_justseconds += hours * 3600;
    update();
}

void Time::addMinutes(int minutes)
{
    m_justseconds += minutes * 60;
    update();
}

void Time::addSeconds(int seconds)
{
    m_justseconds += seconds;
    update();
}

void Time::print()
{
    std::cout << "h: " << m_hour << " m: " << m_minute << " s: " << m_second << std::endl;
}