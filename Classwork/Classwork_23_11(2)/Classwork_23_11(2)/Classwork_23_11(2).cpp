#include <iostream>
using namespace std;

class Student
{
private:
	string name;
	string name_of_group;
	int id;
public:
	Student() :name(""), name_of_group(""), id(0){}

	Student(string n, string nog, int id) :name(n), name_of_group(nog), id(id){}


	string GetName()
	{
		return name;
	}
	string Get_Name_Of_Group()
	{
		return name_of_group;
	}
	int GetId()
	{
		return id;
	}

	void SetName(string n)
	{
		name = n;
	}
	void SetNameOfGroup(string nog)
	{
		name_of_group = nog;
	}
	void SetId(int i)
	{
		id = i;
	}
	
	void Input()
	{
		cout << "Enter name: " << endl;
		cin >> name;
		cout << "Enter name of group: " << endl;
		cin >> name_of_group;
		cout << "Enter id: " << endl;
		cin >> id;
	}
	void Output()
	{
		cout << "Name - " << name<<endl;
		cout << "Name of group - " << name_of_group << endl;
		cout << "Id - " << id << endl;
	}
};

int main()
{
	cout << "Enter n: " << endl;
	int n;
	cin >> n;
	Student* student = new Student[n];
	cout << "Enter group: " << endl;
	string group;
	cin >> group;
	string name;
  /*  student->SetNameOfGroup(group);          //1)
	for (int i = 0; i < n; i++)
	{
		student[i].Input();
	}
	for (int i = 0; i < n; i++)
	{
		if (student[i].Get_Name_Of_Group() == group)
		{
			cout << "Name - " << student[i].GetName() << endl;
			cout << "Id - " << student[i].GetId() << endl;
		}
	}*/
	//cout << "Enter name: " << endl;               //2
	//string name_1;
	//cin >> name_1;
	//for (int i = 0; i < n; i++)
	//{
	//	student[i].Input();
	//}
	//for (int i = 0; i < n; i++)
	//{
	//	if (student[i].GetName() == name_1)
	//	{
	//		student[i].Output();
	//	}
	//}
	
	//int new_id;
	//for (int i = 0; i < n; ++i) {
	//	if (name == student[i].GetName()) {
	//		cout << "Enter new id: " << endl;
	//		cin >> new_id;
	//		student[i].SetId(new_id);                                                  //3
	//	}
	//}


	for (int i = 0; i < n; i++)
	{
		student[i].Input();
	}


	int count = 0;    
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (student[j].GetId() > student[j + 1].GetId())
			{
				swap(student[j].GetId(), student[j + 1].GetId());
				count++;
			}
		}
	}
