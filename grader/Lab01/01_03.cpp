#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

vector<int> findDuplicates(vector<int> a, vector<int> b)
{
    vector<int> result;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
        {
            result.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return result;
}

int main()
{
    string input;
    vector<int> a;
    vector<int> b;

    getline(cin, input);
    istringstream a_stream(input);
    int x;
    while (a_stream >> x)
    {
        a.push_back(x);
    }

    getline(cin, input);
    istringstream b_stream(input);
    while (b_stream >> x)
    {
        b.push_back(x);
    }

    vector<int> result = findDuplicates(a, b);

    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
