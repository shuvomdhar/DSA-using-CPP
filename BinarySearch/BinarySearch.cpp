#include<bits/stdc++.h>
using namespace std;

int binarySearch(int sz, int a[], int target) {
    int low = 0, high = sz - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == target) {
            return mid;
        }
        else if (a[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements into the array in the sorted order:- " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    int target;
    cout << "Enter the target element: ";
    cin >> target;
    if (binarySearch(size, arr, target) != -1)
    {
        cout << target << " found at index " << binarySearch(size, arr, target) << endl;
    }
    else
    {
        cout << "Element not found!!" << endl;
    }
    return 0;
}