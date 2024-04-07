#include <iostream>
using namespace std;

void BubbleSort(int arr[]) {
    int n = 5, i, j;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
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

    BubbleSort(arr);

    cout << "After sorted : ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}