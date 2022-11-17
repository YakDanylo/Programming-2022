#include <iostream>
using namespace std;

void inputMatrix(int arr, int size)
{
    cout << "Enter your Matrix: " << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "Input" << "[" << i << "] [" << j << "]: ";
            cin >> arr[i][j];
        }
        cout << endl;
    }
}

void outputMatrix(int arr, int size)
{
    cout << "Your Matrix: " << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << " " << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool check(int** arr, int size)
{
    bool check = true;
    int sumOfRow = 0;
    int sumOfCol = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sumOfRow += arr[i][j];
        }
        for (int k = 0; k < size; k++)
        {
            for (int l = 0; l < size; l++)
            {
                sumOfCol += arr[l][k];
            }
            if (sumOfRow != sumOfCol)
            {
                check = false;
            }
            sumOfCol = 0;
        }
        sumOfRow = 0;
    }
    return check;

}
int main()
{
    cout << "Size of matrix nxn: ";
    int n;
    cin >> n;

    int** arr = new int* [n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    inputMatrix(arr, n);
    outputMatrix(arr, n);
    if (check(arr, n))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    // delete
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
}