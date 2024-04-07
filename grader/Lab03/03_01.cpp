#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<double> merge(vector<double>& list1, vector<double>& list2) {
  vector<double> mergedList;

  // Initialize iterators to the beginning of the lists
  vector<double>::iterator it1 = list1.begin();
  vector<double>::iterator it2 = list2.begin();

  while (it1 != list1.end() && it2 != list2.end()) {
    // Add the smaller of the two elements to the merged list
    if (*it1 < *it2) {
      mergedList.push_back(*it1);
      ++it1;
    } else {
      mergedList.push_back(*it2);
      ++it2;
    }
  }

  // Add any remaining elements from list1
  while (it1 != list1.end()) {
    mergedList.push_back(*it1);
    ++it1;
  }

  // Add any remaining elements from list2
  while (it2 != list2.end()) {
    mergedList.push_back(*it2);
    ++it2;
  }

  return mergedList;
}

int main() 
{
    string input;
    double a_size = 0, b_size = 0, element, count = 1;

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

    if (a_size == 0 && b_size == 0) {
      return 0;
    }

    vector<double> a, b;
    a.reserve(a_size);
    b.reserve(b_size);

    // Input the elements of list A
    getline(cin, input);
    istringstream a_stream(input);
    while (a_stream >> element) {
        if (element == (double)element) {
            a.push_back(element);
        }
    }

    // Input the elements of list B
    getline(cin, input);
    istringstream b_stream(input);
    while (b_stream >> element) {
        if (element == (double)element) {
            b.push_back(element);
        }
    }

    vector<double> merged;
    merged.reserve(a_size + b_size);
    merged = merge(a, b);

    // cout << "Merge" << endl;
    // for (double i : merged) cout << i << " ";
    // cout << endl;

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

// 0 2
//   
// 10 20

// 0 5
//         
// 1 2 3 4 5

// 0 4
//
// 1 2 3 4 

// 0 0
//
//