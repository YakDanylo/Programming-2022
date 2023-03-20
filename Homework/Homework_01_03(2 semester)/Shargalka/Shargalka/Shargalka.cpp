#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Shpargalka
{
protected:
    string subject;
    int number;
public:
    Shpargalka() :subject(""), number(0) {}
    virtual void input(istream& is) = 0;
    
    virtual void output(ostream& os) = 0;

    virtual string get_name_of_carrier() = 0;
    
    
    string get_subject()
    {
        return subject;
    }
    int get_number()
    {
        return number;
    }

};

class PaperShpora : public Shpargalka
{
private:
    int size;
    string hiding_place;
public:
    void input(istream& is)
    {
        is >> subject >> number >> size >> hiding_place;
    }
    
    void output(ostream& os)
    {
        os << " Subject: " << subject << " Number: " << number << " Size: " << size << " Hiding place: " << hiding_place<<endl;
    }
    string get_name_of_carrier()
    {
        return "";
    }
};

class ElectroShpora : public Shpargalka
{
private:
    string nameOfCarrier;
public:
    

    void input(istream& is)
    {
        is >> subject >> number >> nameOfCarrier;
    }
    void output(ostream& os)
    {
        os << "Subject: " << subject << " Number: " << number << " NameOfCarrier: " << nameOfCarrier << endl;
    }
    string get_name_of_carrier()
    {
        return nameOfCarrier;
    }
};

class Student
{
protected:
    string name;
    string group;
    vector<Shpargalka*> arr;
public:
    Student() :name(""), group("") {}
    friend istream& operator>>(istream& is, Student& st)
    {
        is >> st.name >> st.group;
        return is;
    }

    void input(istream& is)
    {
        is >> name >> group;
    }
    void output(ostream& os)
    {
        os << "Student name: " << name << " Student group: " << group; 
    }
    void addShpora(Shpargalka* shpora) {
        arr.push_back(shpora);
    }
    vector<Shpargalka*> getShpora() {
        return arr;
    }
};


int main()
{
    int i = -1;
    ifstream file("Students.txt");
    vector <Student> studentsArr;
    int sizeOfArray = studentsArr.size();
    while (!file.eof())
    {
        
        Student* tempSt;
        Shpargalka* tempShp;
        char type;
        file >> type;
        if (type == 'S')
        {
            tempSt = new Student;
            tempSt->input(file);
            studentsArr.push_back(*tempSt);
            i++;
        }
        else if (type == 'P')
        {
            tempShp = new PaperShpora;
            tempShp->input(file);
            studentsArr[i].addShpora(tempShp);
        }
        else if (type == 'E')
        {
            tempShp = new ElectroShpora;
            tempShp->input(file);
            studentsArr[i].addShpora(tempShp);
        }
    }

    ofstream SortedByNames("sorted_by_name.txt");
    
    
    vector <Shpargalka*> newArr;
    

    for (int i = 0; i < studentsArr.size(); i++)
    {
        vector <Shpargalka*> temp = studentsArr[i].getShpora();
        for (int j = 0; j < temp.size(); j++)
        {
            newArr.push_back(temp[j]);
            
        }
    }
    for (int i = 0; i < newArr.size(); i++)
    {
        for (int j = 0; j < newArr.size(); j++)
        {
            if (newArr[i]->get_subject() < newArr[j]->get_subject())
            {
                swap(newArr[i], newArr[j]);
            }
        }
    }
    for (int i = 0; i < newArr.size(); i++)
    {
        newArr[i]->output(SortedByNames);
    }
    
    ofstream file3("sorted_by_number.txt");

    for (int i = 0; i < newArr.size(); i++)
    {
        for (int j = 0; j < newArr.size(); j++)
        {
            if (newArr[i]->get_number() < newArr[j]->get_number())
            {
                swap(newArr[i], newArr[j]);
            }
        }
    }
    for (int i = 0; i < newArr.size(); i++)
    {
        newArr[i]->output(file3);
    }

    ofstream comps("comps.txt");
    int count=0;
    for (int i = 0; i < newArr.size(); i++)
    {
        if (newArr[i]->get_name_of_carrier() == "Comp")
        {
            count++;
            newArr[i]->output(comps);
            
        }
    }
    comps << "Number of comps carriers - " << count;
}
