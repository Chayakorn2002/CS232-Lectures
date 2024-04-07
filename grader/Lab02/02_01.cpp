#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// We're using the tim sort!

const int MIN_RUN = 32;

void insertion_sort(vector<int> &numbers, int left, int right)
{
    for (int i = left + 1; i < right; i++)
    {
        int j = i;
        while (j > left && numbers[j] < numbers[j - 1])
        {
            int temp = numbers[j];
            numbers[j] = numbers[j - 1];
            numbers[j - 1] = temp;
            j--;
        }
    }
}

void merge(vector<int> &numbers, int left, int mid, int right)
{
    int i = left;
    int j = mid;
    vector<int> temp;

    while (i < mid && j < right)
    {
        if (numbers[i] < numbers[j])
        {
            temp.push_back(numbers[i]);
            i++;
        }
        else
        {
            temp.push_back(numbers[j]);
            j++;
        }
    }

    while (i < mid)
    {
        temp.push_back(numbers[i]);
        i++;
    }

    while (j < right)
    {
        temp.push_back(numbers[j]);
        j++;
    }

    for (int k = left; k < right; k++)
    {
        numbers[k] = temp[k - left];
    }
}

void tim_sort(vector<int> &numbers)
{
    int n = numbers.size();
    for (int i = 0; i < n; i += MIN_RUN)
    {
        insertion_sort(numbers, i, min(i + MIN_RUN, n));
    }

    for (int size = MIN_RUN; size < n; size *= 2)
    {
        for (int i = 0; i < n; i += 2 * size)
        {
            int mid = i + size;
            int right = min(i + 2 * size, n);
            merge(numbers, i, mid, right);
        }
    }
}

int main() 
{

    // input !
    string input;
    vector<int> numbers;

    getline(cin, input);
    istringstream input_stream(input);
    int x;

    while (input_stream >> x) 
    {
        numbers.push_back(x);
    }

    // tim sort!!!
    tim_sort(numbers);

    // output!
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
}