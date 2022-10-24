//#include<iostream>
//#include<math.h>
//using namespace std;
//
//int main()
//{
//	int n, a, b;                                     //task 25 a)
//	cout << "Enter n: " << endl;
//	cin >> n;
//	cout << "Enter a: " << endl;
//	cin >> a;
//	cout << "Enter b: " << endl;
//	cin >> b;
//
//	if (a == b)
//	{
//		cout << "a=b, wrong!";
//		return 0;
//	}
//
//	int h = (b - a) / n;
//	for (int i = 0;i <= n;i++)
//	{
//		int r = a + (i * h);
//
//		cout << "r" << i << "= " << r << endl;
//	}
//
//	return 0;
//
//	//------------------------------------------------------------------------------------ ;
//
//
//	double lesser = 0; //ë³÷èëüíèê ÷ëåí³â, ìåíøèõ çà 0.25                   //25 á
//	for (double k = 1; k <= 1000; k *= 2)
//	{
//		double ak = pow(sin(3 * k + 5), 2) - pow(cos(pow(k, 2) - 15), 2);
//		if (ak < 0.25)
//		{
//			lesser++;
//		}
//	}
//	cout << lesser;
//}