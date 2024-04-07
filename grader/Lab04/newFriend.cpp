#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int num;
    string n,input;
    vector<int> a;
    vector<int> b;
    getline(cin,n);
    if(n == "0"){
        return 0;
    }else{
        bool check = true;
        getline(cin, input);
        istringstream a_stream(input);
        num = stoi(n);
        int x;
        while (a_stream >> x)
        {
            a.push_back(x);
        }
        int s = a.size();
        if(num == 1){
            if(s > num){
                cout << "`Out of range`";
            }
        }else{
            if(s > num-1){
                cout << "`Out of range`";
            }
        }
        int arr[num];
        for(int i = 0;i < num ;i++){
            arr[i] = 0; 
        }
        for(int x : a){
            if(x > num){
                return 0;
            }else{
                arr[x-1] = x;
            }
        }

        for(int i = 0;i<num;i++){
                if(arr[i] == 0 && check){
                    cout << i+1;
                }
            }
    }
    return 0;
}