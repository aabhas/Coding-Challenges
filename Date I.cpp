#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>


int date_track(int date, int weekday)
{

	if(weekday == 0)
		return date;

	int day = date % 7;
	if((abs(weekday) < 7)&&(abs(weekday) > day))
	{
		return weekday + date; 
	}
	else if((abs(weekday) < 7)&&(weekday < day))
		int new_weekday = 7 + (weekday%7);
	else if(weekday >= 7)
		int new_weekday = weekday;

	date = date - day;	//gives you the monday
	if(weekday > 0)
		return date + (weekday%7) + 7*(1 + weekday/7);
	else
		return date - new_weekday;
}