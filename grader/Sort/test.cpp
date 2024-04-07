#include <iostream>
using namespace std;

int main()
{
    int count = 0, n = 2;
    for (int i = n / 2; i <= n; i++) {
        cout << "i : " << i;
        for (int j = 1; j+n/2 <=n; j = j++) {
            cout << "j : " << j;
            for (int k = 1; k <= n; k = k * 2) {
                count ++;
                cout << "k : " << k; 
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}