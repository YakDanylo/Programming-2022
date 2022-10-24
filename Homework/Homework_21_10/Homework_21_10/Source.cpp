#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	double e = pow(10, -5);

	double a, h,x,y,p;
	
	double xl[10], yl[10], sl[10], pl[10];

	cin >> a >> h;
	x = a;
	double S=1;
	
	double k=1, l=2,i=1;
	for (int j = 0; j < 10; j++)
	{
		while ((pow(x,i) * k / l) - pow(x, i + 1) * (k * (2 * i + 1)) / (l * 2 * (i + 1)) >= e)
		{
			
			S += (pow(x, i) * k) / l;
			k *= 2 * i + 1;
			l *= 2 * (i + 1);
			i+=1;

		}
		y = pow(1 - x, -0.5);
		p = abs((S - y) / y) * 100;
		xl[j] = x;
		yl[j] = y;
		sl[j] = S;
		pl[j] = p;
		x += h;
		
	}
	for (int j = 0; j < 10; j++)
	{
		cout << "x= " << xl[j] << " y= " << yl[j] << " S= " << sl[j] << " p= " << pl[j]<<endl;
	}
}