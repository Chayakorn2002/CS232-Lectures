#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m,max = 0,j=0;
    string line,num;
    getline(cin,line);
    int s = line.size();
    n = 10;
    vector<int> a(10);

    for(int i = 0 ; i < s; i++)
    {
        if(line[i] == ' '){
            int check = stoi(num);
            a[j] = check;
            if(check > max)
            {
                max = check;
            }
            j++;
            num.clear();
        }
        else{
            num += line[i];
            if((i == s-1))
            {
                int check = stoi(num);
                a[j] = check;
                if(check > max)
                {
                    max = check;
                }
                j++;
                num.clear();
            }
        }
    }

    cin >> m;

    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    for(int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(j < a[i-1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
        }
    }

    if(dp[n][m]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
