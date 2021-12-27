
#ifndef TIME_H_
#define TIME_H_

class Time {
public:

	Time (int hour=0, int minute=0, int second=0);
	int second () const { return _second; }
	int minute () const { return _minute; }
	int hour () const { return _hour; }
	int justseconds () ;
	int diff (Time a, Time b) ;
	void add (Time a) ;
	void add_hours(int hour) ;
	void add_minutes(int minute) ;
	void add_seconds(int second);
	void check_beginn () ;
	void ausgabe ();
	void ueberlauf (int jsecs);

private:
	int _second;
	int _minute;
	int _hour;

};



#endif /* TIME_H_ */
