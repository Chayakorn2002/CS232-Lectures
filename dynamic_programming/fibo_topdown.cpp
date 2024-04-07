// Finding the nth Fibonacci number Fn, where, F0 = 0, F1 = 1, For all i ≥ 2 , Fi = Fi-1 + Fi-2
#include <iostream>
using namespace std;

int nth_fibo(int n, int arr[])
{
    if (arr[n] != -1) {
        return arr[n];
    }

    arr[n] = nth_fibo(n - 1, arr) + nth_fibo(n - 2, arr);

    return arr[n];
}

int main()
{
    int n;
    cin >> n;

    int arr[n + 1];
    arr[0] = 0, arr[1] = 1;

    // initialize all the array's member with -1 so we can check if the nth exist with -1 
    // or else the arr will store the value with the trash in memory... right?
    for (int i = 2; i < n + 1; i++) {
        arr[i] = -1;
    }

    cout << "fibo " << n << "th: " << nth_fibo(n, arr) << endl;

    return 0;
}