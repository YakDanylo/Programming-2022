#include<iostream>
using namespace std;

int main()
{
	cout << "Enter length" << endl;
	int m, n;
	cin >> m;
	cout << "Enter Width" << endl;
	cin >> n;
	//entering the array
	int myArray[100][100];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> myArray[i][j];
		}	
	}
	//breeding the array
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << myArray[i][j]<<" ";
		}
		cout << endl;
	}

	cout << "---------------------------------------------------" << endl;
	//matrix columns with odd numbers
	cout << "matrix columns with odd numbers" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j <= n; j+=2)
		{
			cout << myArray[i][j-1] << " ";
		}
		cout << endl;
	}

	cout << "---------------------------------------------------" << endl;
	
	for (int i = 1; i <= m; i+=2)
	{
		for (int j = 1; j <= n; j += 2)
		{
			cout << myArray[i-1][j-1] << " ";
		}
		cout << endl;
	}
}