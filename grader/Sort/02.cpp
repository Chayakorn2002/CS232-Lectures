#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[end], i = start - 1, temp;
    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;
    // swap(&arr[i + 1], &arr[end]);
    return i;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end) {
        int pivot = partition(arr, start, end);
        quickSort(arr,start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}

int main()
{
    int n;
    cin >> n;

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        cout << "Out of range";
        return 0;
    }

    n = n - 1;

    int arr[n - 1];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > n + 1) {
            cout << "Out of range";
            break;
        } 
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            cout << i + 1;
            break;
        }
    }
    return 0;
}

// 6 8 1 9 7 10 3 5 2