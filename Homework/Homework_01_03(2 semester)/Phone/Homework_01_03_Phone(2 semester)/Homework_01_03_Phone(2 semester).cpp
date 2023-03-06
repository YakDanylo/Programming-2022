#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

class Phone
{
private:
	string brand;
	string model;
	int price;
	bool isAutoAnswered;
public:
	virtual void input(istream& is)
	{
		is >> brand >> model >> price;
	}
	virtual void output(ostream& os)
	{
		os << " Brand: " << brand << " Model: " << model << " Price: " << price;
	}
	bool operator<(Phone& phone)
	{
		if (this->price < phone.price)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int get_price()
	{
		return price;
	}
	virtual bool get_is_Auto_answear()
	{
		return false;
	}
};

class Mobile_Phone : public Phone
{
private:
	string color;
	int memory;
public:
	void input(istream& is)
	{
		Phone::input(is);
		is >> color >> memory;
	}
	void output(ostream& os)
	{
		Phone::output(os);
		os << " Color: " << color << " Memory: " << memory << endl;
	}
};

class Radio_Phone : public Phone
{
private:
	int radius;
	bool isAutoAnswear;
public:
	void input(istream& is)
	{
		
		Phone::input(is);
		is >> radius >>isAutoAnswear;
	}
	void output(ostream& os)
	{
		string temp;
		if (isAutoAnswear)
		{
			temp = "Yes";
		}
		else {
			temp = "No";
		}
		Phone::output(os);
		os << " Radius: " << radius << " Has auto answear: " << temp << endl;
	}
	bool get_is_Auto_answear()
	{
		if(isAutoAnswear)
		{
			return true;
		}
		return false;
	}
};


int main()
{
	
	vector<Phone*> phones;
	ifstream mobiles("Mobile.txt");
	ifstream radios("Radio.txt");
	Phone* temp1;
	while (!mobiles.eof())
	{
		temp1 = new Mobile_Phone;
		temp1->input(mobiles);
		phones.push_back(temp1);
	}
	
	Phone* temp2;
	while (!radios.eof())
	{
		temp2 = new Radio_Phone;
		temp2->input(radios);
		phones.push_back(temp2);
	}
	
	int total_price=0;
	for (int i = 0; i < phones.size(); i++)
	{
		for (int j = i; j < phones.size(); j++)
		{
			if (phones[i]->get_price() > phones[j]->get_price())
			{
				swap(phones[i], phones[j]);
			}
		}
		total_price += phones[i]->get_price();
	}
	for (auto phone : phones)
	{
		phone->output(cout);
		cout << endl;
	}
	cout << "Total price is: "<<total_price<<endl<<endl;
	
	for (int i = 0; i < phones.size(); i++)
	{
		if (phones[i]->get_is_Auto_answear())
		{
			phones[i]->output(cout);
			cout << endl;
		}
	}
	

	


}


