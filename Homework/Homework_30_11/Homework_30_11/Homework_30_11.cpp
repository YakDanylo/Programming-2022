#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

struct Point
{
    double x;
    double y;
    friend ostream& operator<<(ostream& os, Point& point)
    {
        os << "(" << point.x << "," << point.y << ")";
        return os;
    }
};

class Line
{
private:
    double a, b, c;
public:
    Line() : a(0), b(0), c(0) {}
    Line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
    Line(const Line& p) : a(p.a), b(p.b), c(p.c) {}
    friend istream& operator>>(istream& is, Line& line)
    {
        is >> line.a >> line.b >> line.c;
        return is;
    }
    friend ostream& operator<<(ostream& os, Line& line)
    {
        os << line.a << " x + " << line.b << " y +  " << line.c << " z " << " = 0 " << endl;
        return os;
    }
    Point getInterception(Line& line)
    {
        double bottom = a * line.b - line.a * b;
        double x = (b * line.c - line.b * c) / bottom;
        double y = (c * line.a - line.c * a) / bottom;
        Point p;
        p.x = x;
        p.y = y;
        return p;
    }
    bool isinter(Line& l2)
    {
        double bottom = a * l2.b - l2.a * b;
        if (bottom == 0)
        {
            return false;
        }
        else { return true; }
    }
    double GetAngle(Line& line2)
    {
        double angle = (line2.a * a + line2.b * b) / (sqrt(line2.a * line2.a + line2.b * line2.b) * sqrt(a * a + b * b));
        return angle;
    }
    bool isonaline(Point& p)
    {
        if (a * p.x + b * p.y + c == 0)
        {
            return true;
        }
        else {
            return false;
        }
    }
};
int main()
{
    int n = 10;
    Line line;
    Line* array = new Line[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            if (array[i].isinter(array[j]))
            {
                Point p = array[i].getInterception(array[j]);
                cout << "Line " << array[i] << " intersects " << array[j] << endl;
                cout << "Point of interseption is: " << p << endl;
            }
        }
    }
    int c1 = 0, c2 = 0;
    Line Ox(0, 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (!array[i].isinter(Ox))
        {
            c1++;
        }
        else if (array[i].GetAngle(Ox) == M_PI_2)
        {
            c2++;
        }
        cout << c1 << " " << endl;
        cout << c2 << endl;
    }

}


