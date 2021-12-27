#include <iostream>
#include "time.h"



Time::Time (int hour, int minute, int second) {
	_hour = hour;
	_minute = minute;
	_second = second;
	ueberlauf(justseconds());
}



int Time::justseconds() {
	int seconds = _hour * 3600 + _minute * 60 + _second;
	return (seconds);
}

int Time::diff(Time a, Time b) {
	int seconds_a = a.justseconds();
	int seconds_b = b.justseconds();
	int diff = seconds_a - seconds_b;
	return diff;
}

void Time::add(Time a) {
	_hour += a.hour();
	_minute += a.minute();
	_second += a.second();
	ueberlauf (0);
	check_beginn();
}

void Time::add_hours(int hour) {
	ueberlauf (hour * 3600);
	check_beginn();
}

void Time::add_minutes(int minute) {
	ueberlauf (minute * 60);
	check_beginn();
}

void Time::add_seconds(int second) {
	ueberlauf (second);
	check_beginn();
}

void Time::check_beginn() {
	if (justseconds() < 0) {
		_hour = 0;
		_minute = 0;
		_second = 0;
		std::cout << "Zeit wurde auf Anfang gesetzt" << std::endl;
		ausgabe ();
	}
}

void Time::ausgabe() {
	std::cout << _hour << "h:" << _minute << "m:" << _second << "s" << std::endl;
}

void Time::ueberlauf(int sec) {
	int alt = justseconds();
	int neu = alt + sec;
	_hour = neu / 3600;
	int hr = neu % 3600;
	_minute = hr / 60;
	int mr = hr % 60;
	_second = mr;
}

