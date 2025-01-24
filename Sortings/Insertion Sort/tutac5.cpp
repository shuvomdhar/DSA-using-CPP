#include <iostream>
using namespace std;

void insertion_sort(int size, int arr[])
{
    
}

void printarray(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size, key;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter elements in the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Your array: ";
    printarray(size, arr);
    insertion_sort(size, arr);
    cout << "Sorted array: ";
    printarray(size, arr);
    return 0;
}