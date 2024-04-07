#include <iostream>
using namespace std;

// idea of merge sort : ecursiely divide the array in 2, sort them, recombine them!
// time-complexity : O(nlogn)
// space-complexity : O(n)

void merge(int arr[], int start, int mid, int end)
{
    int i, l, r;
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int leftArr[leftSize], rightArr[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArr[i] = arr[start + i];
    for (int j = 0; j < rightSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    i = start, l = 0, r = 0;

    while (l < leftSize && r < rightSize)
    {
        if (leftArr[l] < rightArr[r])
        {
            arr[i] = leftArr[l];
            l++;
        }
        else
        {
            arr[i] = rightArr[r];
            r++;
        }
        i++;
    }
    while (l < leftSize)
    {
        arr[i] = leftArr[l];
        l++;
        i++;
    }
    while (r < rightSize)
    {
        arr[i] = rightArr[r];
        r++;
        i++;
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    // int size = sizeof(arr) / sizeof(int);

    cout << "Before Sorting : ";

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    mergeSort(arr, 0, size - 1);

    cout << "After Sorting : ";

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}