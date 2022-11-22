#include <iostream>
using namespace std;

enum Day
{
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY,
    NODAY = -1,
};
string Output_day_str(Day arr[], int n)
{
    if (n == 1)
    {
        string day = "Monday";
        return day;
    }
    else if (n == 2)
    {
        string day = "Tuesday";
        return day;
    }
    else if (n == 3)
    {
        string day = "Wednesday";
        return day;
    }
    else if (n == 4)
    {
        string day = "Thursday";
        return day;
    }
    else if (n == 5)
    {
        string day = "Friday";
        return day;
    }
    else if (n == 6)
    {
        string day = "Saturday";
        return day;
    }
    else if (n == 7)
    {
        string day = "Sunday";
        return day;
    }

}

Day str_to_Day(string day_name, int n)
{
    for (int i = 0; i < n; ++i)
    {
        day_name[i] = tolower(day_name[i]);
    }
    if (day_name == "monday" || day_name == "mon")
    {
        return MONDAY;
    }
    else if (day_name == "tuesday" || day_name == "tues")
    {
        return TUESDAY;
    }
    else if (day_name == "wednesday" || day_name == "wed")
    {
        return WEDNESDAY;
    }
    else if (day_name == "thursday" || day_name == "thurs")
    {
        return THURSDAY;
    }
    else if (day_name == "friday" || day_name == "fri")
    {
        return FRIDAY;
    }
    else if (day_name == "saturday" || day_name == "sat")
    {
        return SATURDAY;
    }
    else if (day_name == "sunday" || day_name == "sun")
    {
        return SUNDAY;
    }
    else
    {
        return NODAY;
    }
}
int main()
{
    /*Day *day = new Day[7];*/

    /*cout << "Enter number of day: " << endl;
    int n;
    cin >> n;
    cout<< Output_day_str(day, n)<<endl;
    cout << "Enter name of day: ";
    string day_name;
    cin >> day_name;
    cout << Output_day_int(day, day_name);*/
    int mon = 0, tue = 0, wed = 0, thu = 0, fri = 0, sat = 0, sun = 0;
    string day_name;
    int n;
    cout << "Enter n: " << endl;
    cin >> n;
    int* mas = new int[n];
    Day* day = new Day[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter day: " << endl;
        cin >> day_name;

        day[i] = str_to_Day(day_name, n);
        cout << day[i] << endl;
    }

    int count = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (day[j] > day[j + 1]) {
                swap(day[j], day[j + 1]);
                count++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (day[i] == 1)
        {
            mon++;
            cout << "Monday - " << mon << endl;
        }
        else if (day[i] == 2)
        {
            tue++;
            cout << "Tuesday - " << tue << endl;
        }
        else if (day[i] == 3)
        {
            wed++;
            cout << "Wednesday - " << wed << endl;
        }
        else if (day[i] == 4)
        {
            thu++;
            cout << "Thursday - " << thu << endl;
        }
        else if (day[i] == 5)
        {
            fri++;
            cout << "Friday - " << fri << endl;
        }
        else if (day[i] == 6)
        {
            sat++;
            cout << "Saturday - " << sat << endl;
        }
        else if (day[i] == 7)
        {
            sun++;
            cout << "Sunday - " << sun << endl;
        }
    }
}



