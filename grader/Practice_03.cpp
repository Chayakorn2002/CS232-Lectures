#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int min = 1000, temp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            temp = abs(arr[i][j] - arr[i][j + 1]);
            if (temp < min) {
                min = temp;
            }
        }
    }

    cout << min;

    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // return 0;
}
// 1 6 5 3 4 3 7 9 3 8 2 4 6 9 5 7