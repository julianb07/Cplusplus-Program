#include<iostream>
using namespace std;
//Beginning of _OneDay class
class _OneDay;
class Time
{
	public:
		int hour;
		int minute;
		int second;
		virtual void Hour() = 0;
		virtual void Minute() = 0;
		virtual void Second() = 0;
};
// Inheriting Time class
class _HalfDay: public Time
{
public:
	_HalfDay(int S,int M,int H)
	{
		second = S;
		minute = M;
		hour = H;
	}
	void Second()
	{
		if(second==59)
		{
			second=0;
			Minute();
		}
		else
		{
			second+=1;
		}
	void Minute()
	{
		if(minute==59)
		{
			minute=0;
			Hour();
		}
		else
		{
			minute+=1;
		}
	}
	void Hour()
	{
		if(hour==11){
			hour = 0;
		}
		else
		{
			hour+=1;

		}
	}


	}
	friend void Clock(const_HalfDay&,const_OneDay&);
};
//Inheriting Time class for _OneDay
class _OneDay:public Time
{
public:
	_OneDay(int S,int M,int H)
	{
		second = S;
		minute = M;
		hour = H;
	}
	void Second()
	{
		if(second==59)
		{
			second=0;
			Minute();
		}
		else
		{
			second+=1;
		}
	}
	void Minute()
	{
		if(minute==59)
		{
			minute=0;
			Hour();
		}
		else
		{
			minute+=1;
		}
	}
	void Hour()
	{
		if(hour==23)
		{
			hour=0;
		}
		else
		{
			hour+=1;
		}
	}


	friend void Clock(const _HalfDay&,const _OneDay&)
};
//Void used for displaying the time of the clock
void Clock(const _HalfDay& 12hour,const _OneDay& 24hour)
{
	cout<<" 12-Hour Clock ** 24-Hour Clock \n";
	cout<<" ";if(12hour.hour<10)cout<<"0";cout<<12hour.hour<<":";
	if(12hour.minute<10)cout<<"0";cout<<12hour.minute<<":";
	if(12hour.second<10)cout<<"0";cout<<12hour.second;
	cout<<endl;
	if(24hour.hour<10)cout<<"0";cout<<24hour.hour<<":";
	if(24hour.minute<10)cout<<"0";cout<<24hour.minute<<":";
	if(24hour.second<10)cout<<"0";cout<<24hour.second;
	cout<<endl;
}
//Display of the options to change the time
int main()
{
	_HalfDay 12_hour_clock(11,59,59);
	_OneDay 24_hour_clock(23,59,59);
	Clock(12_hour_clock, 24_hour_clock);
	while(true)
	{
		cout<<endl;
		cout<<" 1 Add Second \n";
		cout<<" 2 Add Minute \n";
		cout<<" 3 Add Hour \n";
		cout<<" 4 Exit Program \n";
		cout<<endl;
		int input;
		if (input == '1')
		{
		12_hour_clock.Second();
		24_hour_clock.Second();
		Clock(12_hour_clock, 24_hour_clock);
		}
		else if (input == '2')
		{
		12_hour_clock.Minute();
		24_hour_clock.Minute();
		Clock(12_hour_clock, 24_hour_clock);
		}
		else if (input == '3')
		{
		12_hour_clock.Hour();
		24_hour_clock.Hour();
		Clock(12_hour_clock, 24_hour_clock);
		}
		else if (input == '4')
		{
		cout<<"Good Bye";
		return 0;
		}
		else
		{
			cout<<"Enter a valid option";
		}
	}
	return 0;
}
