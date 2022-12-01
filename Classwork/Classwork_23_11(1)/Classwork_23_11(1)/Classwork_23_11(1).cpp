#include<iostream>
using namespace std;

class Car
{
private:
	int price;
	string name;
	string color;
public:
	Car() : price(0), name(" "), color("")
	{

	}
	Car(int p, string n, string c) :price(p), name(n), color(c) {}
	int Get_Price()
	{
		return price;
	}
	string Get_Name()
	{
		return name;
	}
	string Get_color()
	{
		return color;
	}
	void Set_Price(int new_price)
	{
		price = new_price;
	}
	void Input()
	{
		cout << "Enter price: " << endl;
		cin >> price;
		cout << "Enter name: " << endl;
		cin >> name;
		cout << "Enter color: " << endl;
		cin >> color;
	}
	void Print()
	{
		cout << "Price - " << price << endl;
		cout << "Name - " << name << endl;
		cout << "Color - " << color << endl;
	}

};

int main()
{
	Car car1;
	Car car2(10000, "Opel", "Green");
	cout << "Enter n: " << endl;
	int n;
	cin >> n;
	Car* car_array = new Car[n];
	car_array[0] = car1;
	car_array[1] = car2;
	for (int i = 0; i < n - 2; i++)
	{
		cout << "Enter price: " << endl;
		car_array[i].Input();
	}
	cout << "Enter color: " << endl;
	string color;
	cin >> color;

	for (int i = 0; i < n; i++)
	{
		if (car_array[i].Get_color() == color)
		{
			car_array[i].Print();
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (car_array[i].Get_color() == "gold")
		{
			car_array[i].Set_Price(car_array[i].Get_Price() * 0.9);
		}
		car_array[i].Print();
	}
}