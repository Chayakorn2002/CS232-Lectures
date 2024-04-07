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
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};

    quickSort(arr, 0, 7);

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}