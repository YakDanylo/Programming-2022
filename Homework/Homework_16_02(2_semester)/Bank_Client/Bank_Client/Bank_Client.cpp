#include <iostream>
using namespace std;

class Client
{
private:
    string name;
    string adress;
    long int phoneNumber;

public:
    Client():name(" "),adress(" "),phoneNumber(0){}
    Client(string name, string adress, int phoneNumber)
    {
        this->name = name;
        this->adress = adress;
        this->phoneNumber = phoneNumber;
    }
    friend istream& operator>>(istream& is, Client& client)
    {
        is >> client.name;
        is >> client.adress;
        is >> client.phoneNumber;
        return is;
    }
    friend ostream& operator<<(ostream& os, Client& client)
    {
        os << "Name: " << client.name << " Adress: " << client.adress << " Phone number: " << client.phoneNumber << endl;
        return os;
    }
    string getName()
    {
        return name;
    }
    string getAdress() 
    {
        return adress;
    }
};

class bankAccount
{
private:
    Client client;
    int accountNumber;
    int balance;
public:
    bankAccount():client(client), accountNumber(0),balance(0){}
    bankAccount(Client client, int accountNumber, int balance)
    {
        this->client = client;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }
    friend istream& operator>>(istream& is, bankAccount& bankAccount)
    {
        is >> bankAccount.client;
        is >> bankAccount.accountNumber;
        is >> bankAccount.balance;
        return is;
    }
    friend ostream& operator<<(ostream& os, bankAccount& bankAccount)
    {
        os <<"Client: " << bankAccount.client << " Acoount number: " << bankAccount.accountNumber << " Balance: " << bankAccount.balance << endl;
        return os;
    }
    
    int addBalance(int value)
    {
        return balance += value;
    }
    int removeBalance(int value)
    {
        return balance -= value;
    }
    void showBalance()
    {
        cout << "Your balance: " << balance << endl;
    }
    void showInfo()
    {
        cout << "Client name: " << client << endl << " Account number: " << accountNumber << endl << " Balance: " << balance << endl;
    }
    bool FindClientByName(string clientName)
    {
        if (this->client.getName() == clientName)
        {
            cout << client <<" Account number: "<< accountNumber <<" Balance: " << balance;
            return true;
        }
        return false;
    }
    bool FindClientByAdress(string adress)
    {
        if (this->client.getAdress() == adress)
        {
            cout << client << " Account number: " << accountNumber << " Balance: " << balance;
            return true;
        }
        return false;
    }
    
    
};

int main()
{
    bankAccount arrayOfBanks[10];
    //Entering the array
    for (int i = 0; i < 10; i++)
    {
        cin >> arrayOfBanks[i];
    }

    cout << endl;

    // Searching by name
    cout << "Enter name: ";
    string clientName;
    cin >> clientName;
    int idFromNames;
    for (int i = 0; i < 10; i++)
    {
        if (arrayOfBanks[i].FindClientByName(clientName))
        {
            idFromNames = i;
        }
    }

    cout << endl;
   /* for (int i = 0; i < 3; i++)
    {
        arrayOfBanks[i].showInfo();      showing info about all users
    }*/
    //Searching by Adress
    cout << "Enter adress to find client: ";
    string adress;
    cin >> adress;
    int idFromAdress;
    for (int i = 0; i < 10; i++)
    {
        if (arrayOfBanks[i].FindClientByAdress(adress))
        {
            idFromAdress = i;
        }
    }
    cout << endl;

    cout << "Enter name: ";
    string User;
    cin >> User;

    int id;
    for (int i = 0; i < 10; i++)
    {
        if (arrayOfBanks[i].FindClientByName(User))
        {
            id = i;
        }
    }

    cout << endl;

    cout << "Enter operation: " << endl << "1. Adding to your balance  " << "2. Minusing from your balance  " << " 3. Showing your balance" << endl;
    //Adding and removing balance
   
    int x;
    cin >> x;
    switch (x)
    {
    case 1: int valueToAdd;
        cout << "Enter value to add: ";
        cin >> valueToAdd;
        arrayOfBanks[id].addBalance(valueToAdd);
        arrayOfBanks[id].showBalance();
        break;
    case 2:
        int valueToMinus;
        cout << "Enter value to minus: ";
        cin >> valueToMinus;
        arrayOfBanks[id].removeBalance(valueToMinus);
        arrayOfBanks[id].showBalance();
        break;
    case 3:
        arrayOfBanks[id].showInfo();
        break;
    }

    
    
}


