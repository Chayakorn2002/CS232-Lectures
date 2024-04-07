#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    string input;
    int a_size = 0, b_size = 0, element, count = 1;

    // size input
    getline(cin, input);
    istringstream size_stream(input);
    while (size_stream >> element) {
        if (count == 1) {
            a_size = element;
            count ++;
        } else {
            b_size = element;
        }
    }

    vector<int> a, b;
    a.reserve(a_size);
    b.reserve(b_size);

    // Input the elements of list A
    getline(cin, input);
    istringstream a_stream(input);
    while (a_stream >> element) {
        if (element == (int)element) {
            a.push_back(element);
        }
    }
    // for (int i = 0; i < a_size; i++) {
    //     cin >> element;
    //     a.push_back(element);
    // }

    // Input the elements of list B
    getline(cin, input);
    istringstream b_stream(input);
    while (b_stream >> element) {
        if (element == (int)element) {
            b.push_back(element);
        }
    }
    // for (int i = 0; i < b_size; i++) {
    //     cin >> element;
    //     b.push_back(element);
    // }

    vector<int> merged;
    merged.reserve(a_size + b_size);
    merge(a.begin(), a.end(), b.begin(), b.end(), merged.begin());

    cout << "Merge" << endl;
    for (int i : merged) cout << i << " ";
    cout << endl;

    double med;
    int length = merged.size();

    if (length % 2 == 0) {
        med = (merged[length / 2 - 1] + merged[length / 2]) / 2.0;
    } else {
        med = merged[length / 2];
    }

    cout << med;
}

// 4 6
// 2 3 5 8
// 10 12 14 16 18 20

// 2 1
// -3 -1
// -2