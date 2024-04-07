#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {-5, -4, -2, -1, 4, 5, 2, 7};
    int a[5], b[5];
    int acount = 0, bcount = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == -arr[i]) {
            a[acount] = arr[i];
            acount++;
        } else {
            b[bcount] = arr[i];
            bcount++;
        }
    }
    for (int i = 0; i < acount; i++) {
        arr[i] =  a[i];
    }
    for (int i = 0; i < bcount; i++) {
        arr[acount] =  b[i];
    }

    for (int i : arr) {
        cout << arr[i] << " ";
    }
}