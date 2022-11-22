#include <iostream>
using namespace std;

enum Day
{
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY,
};

Day int_to_Day(string day) 
{
	for (int i = 0; i < 5; ++i) {
		day[i] = tolower(day[i]);
	}
	if (day == "monday") {
		return MONDAY;
	}
	else if (day == "tuesday") {
		return TUESDAY;
	}
	else if (day == "wednesday") {
		return WEDNESDAY;
	}
	else if(day=="thursday") 
	{
		return THURSDAY;
	}
	else if (day=="friday")
	{
		return FRIDAY;
	}
	else if (day=="saturday")
	{
		return SATURDAY;
	}
	else if (day=="sunday")
	{
		return SUNDAY;
	}
}

struct Date
{
	int day;
	Day day_of_week;
	int month;
};
int main()
{
	Date *date = new Date[5];
	string day_of_week;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter month (1-12): " << endl;
		cin >> date->month;
		if (date->month==1||date->month==3||date->month==5||date->month==7||date->month==8||date->month==10||date->month==12)
		{
			cout << "Enter day(1-31): " << endl;
			cin >> date->day;
		}
		else if (date->month==4||date->month==6||date->month==9||date->month==11)
		{
			cout << "Enter day(1-30): " << endl;
			cin >> date->day;
		}
		else if (date->month==2)
		{
			cout << "Enter day(1-28): " << endl;
			cin >> date->day;
		}
		cout << "Enter day of week: " << endl;
		cin >> day_of_week;
		if (day_of_week == "monday")
		{
			cout <<"Month - " << date->month << endl;
			cout <<"Day - " << date->day << endl;
		}
		
	}
}


