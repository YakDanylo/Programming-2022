#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Transport
{
protected:
    int engineCapacity;
    string name;
public:
    virtual void input(istream& is)
    {
        is >> engineCapacity >> name;
    }
    virtual void output(ostream& os)
    {
        os << "Engine Capacity: " << engineCapacity << " Name: " << name;
    }
    string get_name()
    {
        return name;
    }
    int get_engine_capacity()
    {
        return engineCapacity;
    }
    virtual bool is_water()
    {
        return false;
    };
    virtual bool is_amphi()
    {
        return false;
    }
};

class Water_transport : virtual public Transport
{
protected:
    string typeOfWater;
    int maxWaterSpeed;
public:
    void input(istream& is)
    {
        Transport::input(is);
        is >> typeOfWater >> maxWaterSpeed;
    }
    void output(ostream& os)
    {
        Transport::output(os);
        os << " Type of water: " << typeOfWater << " Max speed: " << maxWaterSpeed << endl;
    }
    bool is_water()
    {
        return true;
    }
    bool is_amphi()
    {
        return false;
    }
};

class Land_transport : virtual public Transport
{
protected:
    int maxLandSpeed;
    int numberOfSeats;
public:
    void input(istream& is)
    {
        Transport::input(is);
        is >> maxLandSpeed >> numberOfSeats;
    }
    void output(ostream& os)
    {
        Transport::output(os);
        os << " Max speed: " << maxLandSpeed << " Number of seats: " << numberOfSeats << endl;
    }
    bool is_water()
    {
        return false;
    }
    bool is_amphi()
    {
        return false;
    }
};

class Amphibian_transport : public Water_transport, public Land_transport
{
private:
    int HoursInWater;
    int HoursOnLand;
public:
    void input(istream& is)
    {
        is >> engineCapacity >> name;
        is >> typeOfWater >> maxWaterSpeed;  
        is >> maxLandSpeed >> numberOfSeats;
        is >> HoursInWater >> HoursOnLand;
    }
    void output(ostream& os)
    {
        os << "Engine capacity: " << engineCapacity << " Name: " << name;
        os << " Type of water " << typeOfWater << " Max water speed: " << maxWaterSpeed;
        os << " Max land speed: " << maxLandSpeed << " Number of seats: " << numberOfSeats;
        os << " Hours in water: " << HoursInWater << " Hours on land: " << HoursOnLand << endl;

    }
    bool is_water()
    {
        return false;
    }
    bool is_amphi()
    {
        return true;
    }
};
int main()
{
    ifstream file("transports.txt");

    vector <Transport*> transports;
    
    //reading from file

    while (!file.eof())
    {
        Transport* temp_ts;
        char temp;
        file >> temp;
        if (temp == 'A')
        {
            temp_ts = new Amphibian_transport;  
            temp_ts->input(file);
            transports.push_back(temp_ts);
        }
        else if (temp == 'W')
        {
            temp_ts = new Water_transport;
            temp_ts->input(file);
            transports.push_back(temp_ts);
        }
        else if (temp == 'L')
        {
            temp_ts = new Land_transport;
            temp_ts->input(file);
            transports.push_back(temp_ts);
        }
        
    }

    for (int i = 0; i < transports.size(); i++)
    {
        transports[i]->output(cout);   
    }

    

    //Sorting by name

    ofstream SortedByNames("sorted_by_name.txt");

    vector<Transport*> newArr;

    for (int i = 0; i < transports.size(); i++)
    {
        for (int j = i; j < transports.size(); j++)
        {
            if (transports[i]->get_name() > transports[j]->get_name())
            {
                swap(transports[i], transports[j]);
            }
        }
    }
    for (int i = 0; i < transports.size(); i++)
    {
        transports[i]->output(SortedByNames);
    }

    //Finding with the biggest capacity of engine and with the smallest

    Transport* biggestEngine = transports[2];
    Transport* smallestEngine = transports[5];

    for (int i = 0; i < transports.size(); i++)
    {
        if (biggestEngine->get_engine_capacity() < transports[i]->get_engine_capacity())
        {
            biggestEngine = transports[i];
       }
    }
    for (int i = 0; i < transports.size(); i++)
    {
        if (smallestEngine->get_engine_capacity() > transports[i]->get_engine_capacity())
        {
            smallestEngine = transports[i];
        }
    }

    cout << endl << endl;
    cout << "Engine with the smallest capacity: ";
    smallestEngine->output(cout);
    cout << endl;
    cout << "Engine with the biggest capacity: ";
    biggestEngine->output(cout);
    

    //Outputing water and amphibian transport to different files

    ofstream WaterTransport("Water_transport.txt");
    ofstream AmphiTransport("Amphi_transport.txt");

    for (int i = 0; i < transports.size(); i++)
    {
        Transport* temp;
        if (transports[i]->is_amphi())
        {
            temp = transports[i];
            temp->output(AmphiTransport);
        }
        else if (transports[i]->is_water())
        {
            temp = transports[i];
            temp->output(WaterTransport);
        }
    }
}


