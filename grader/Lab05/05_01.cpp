#include <iostream>
#include <vector>
using namespace std;

// brute force O(n^3)
vector<vector<int> > multiply(vector<vector<int> > &a, vector<vector<int> > &b) 
{
    int a_row = a.size(), b_col = b[0].size(), a_b = b.size();
    vector<vector<int> > ans(a_row, vector<int>(b_col));

    for (int i = 0; i < a_row; i++) {
        for (int j = 0; j < b_col; j++) {
            for (int k = 0; k < a_b; k++) {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

int main() 
{
    int ls1[16], ls2[16];
    vector<vector<int> > a(4, vector<int>(4));
    vector<vector<int> > b(4, vector<int>(4));
    int row = 4, col = 4; // 4 x 4

    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) {
            cin >> b[i][j];
        }
    }

    auto ans = multiply(a, b);

    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

// 1 0 2 1 4 1 1 0 0 1 3 0 5 0 2 1
// 0 1 0 1 2 1 0 4 2 0 1 1 1 3 5 0