#include <iostream>
using namespace std;

//23.	��������� �������, skor(a, b, p, q) �� ����� ���������(b 0),
//�� ���������  ��� a / b �� ������������ ���� p / q.
//����������� �� ��� ���������� ����� 1 + 1 / 2 + 1 / 3 + � + 1 / 20 �� ������������ ���� c / d.

void skor(int a, int b,int &p, int &q)
{
	int min = a;
	if (b<a)
	{
		min = b;
	}

	p = a;
	q = b;
	for (int i = 2; i <= min; i++)
	{
		if (p % i == 0 && q % i == 0)
		{
			p = p / i;
			q = q / i;
			i = 1;
		}
	}
}

int* rozv()
{
	int chisel = 1;
    int znamen = 1;
	for (int i = 2; i <= 20; i++)
	{
		chisel = chisel * i + znamen;
		znamen *= i;
		skor(chisel, znamen,chisel,znamen);
		cout << i << ")  " << chisel << "   " << znamen << endl; // Iteration
	}

	int res[2] = { chisel,znamen };
	return res;
}

int main()
{
	int* arr =  rozv();
	cout <<"Res = " << arr[0] <<" / "<<arr[1]; 
}