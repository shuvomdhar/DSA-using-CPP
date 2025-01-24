#include <bits/stdc++.h>
using namespace std;

int linearSearch(int sz, int ar[], int x)
{
    for (int i = 0; i < sz; i++)
    {
        if (ar[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array:- " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    int target;
    cout << "Enter the target element: ";
    cin >> target;
    if (linearSearch(size, arr, target) != -1)
    {
        cout << target << " found at index " << linearSearch(size, arr, target) << endl;
    }
    else
    {
        cout << "Element not found!!" << endl;
    }

    return 0;
}