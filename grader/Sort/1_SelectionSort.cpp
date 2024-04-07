#include <iostream>
using namespace std;

void selectionSort(int arr[]) {
    int min, i, j, n = 5;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

int main() 
{
    int arr[] = {3, 4, 2, 5, 1};

    cout << "Original : ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    selectionSort(arr);

    cout << "After sorted : ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}