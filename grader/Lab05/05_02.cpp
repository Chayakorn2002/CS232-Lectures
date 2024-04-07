#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

void aliveOrNot(int amount, vector<int> &coins) {
    double temp;
    // temp = floor(amount / 10);
    // cout << temp;

    // for (int i : coins) {
    //     cout << i << " ";
    // }
    for (int coin : coins) {
        if (amount - coin >= 0) {
            temp = floor(amount / coin);
            amount -= (coin * temp);
            // cout << "amount : " << amount << endl;
        } else {
            temp = 0;
        }
        cout << coin << ": " << temp << endl;
    }

    if (amount != 0) {
        cout << "Change: " << amount;
    }
}

int main() 
{
    int amount, element;
    string temp; // var for input with spacebar handle
    vector<int> cash;

    getline(cin, temp);
    istringstream a_stream(temp);
    while (a_stream >> element) 
    {
        if (element <= 0) {
            cout << "Just because a thing can be done, does not mean that it should be done.";
            return 0;
        }
        cash.push_back(element);
    }

    cin >> amount;
    
    sort(cash.rbegin(), cash.rend());

    aliveOrNot(amount, cash);

    // for (int i : cash) {
    //     cout << i << " ";
    // }

    return 0;
}
// 1 5 2 20 10
// 69

// 1 2 3 4 5
// 42

// 10 5
// 19

// 1
// 10