#ifndef TIME_H_
#define TIME_H_

#include <iostream>

class Time 
{
public:
    Time(int hour=0, int minute=0, int second=0);

    int hour() const { return m_hour; }
    int minute() const { return m_minute; }
    int second() const { return m_second; }

    void add (Time a);
    void add_hours(int hours);
    void add_minutes(int minutes);
    void add_seconds(int seconds);

    int justseconds() const { return m_justseconds; }
    int diff(Time a, Time b);

    void print();
private:
    void update();
private:
    int m_hour;
    int m_minute;
    int m_second;
    int m_justseconds;
};

#endif 