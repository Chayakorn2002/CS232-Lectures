#include<iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    int cash,x;
    bool check = true;
    string n;
    vector<int> a;

    getline(cin,n);
    istringstream a_stream(n);
    while (a_stream >> x)
        {
            a.push_back(x);
        }
    
    int s = a.size();
    int arr[s],ans[s];
    copy(a.begin(),a.end(),arr);
    //sort max to min

    int len = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr + len, greater<int>());

    for (int i = 0 ; i < s ; i++){
        if(arr[i] < 0){
            check = false;
            cout << "Just because a thing can be done, does not mean that it should be done.";
            cash = 0;
            break;
        }else{
            continue;
        }   
    }

    if(check == true){
        
        cin >> cash;

        for(int i = 0;i < s;i++){
            if(cash / arr[i] < 0){
                ans[i] = 0;
            }else{
                int m = cash / arr[i];
                cash = cash % arr[i];
                ans[i] = m;
            }
        }
    }
    if(check == true){
        for(int i = 0;i < s;i++){
            cout << arr[i] << ": " << ans[i] << endl;
        }
    }
    if(cash != 0){
        cout << "Change: " << cash;
    }
}
