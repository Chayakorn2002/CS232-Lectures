#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n) {
    
    int temp, i, j;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main() 
{
    int arr[] = {3, 4, 2, 5, 1, 9, 8, 7, 10, 6};
    int n = 10;

    cout << "Original : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    InsertionSort(arr, n);

    cout << "After sorted : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}