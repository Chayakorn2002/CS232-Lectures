#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int bug(){
        cout << "What did you expect?"; //What did you expect?
        return 0;    
}

int parent(int *arr,int x){
    return (arr[x]==x)? x : arr[x] = parent(arr,arr[x]);
}

void merge(int *arr,int x,int y){
    arr[parent(arr,y)] = parent(arr,x);
}

int main(){
    int n,e,src;
    long long int ans=0;
    cin >> n >> e;
    if(n<1 || e<0) return bug();
    cin >> src;
    if(src<1 || src>n) return bug();

    vector<pair<int,pair<int,int> > > g;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin >> u >> v >> w;
        if(u<1 || u>n || v<1 || v>n || w<0) return bug();
        if(u==v) continue;
        g.push_back(make_pair(w,make_pair(u,v)));
    }
    sort(g.begin(),g.end());

    int arr[n+1];
    for(int i=0;i<=n;i++) arr[i] = i;

    for(int i=0;i<g.size();i++){
        pair<int,int> p = g[i].second;
        if(parent(arr,p.first)==parent(arr,p.second)) continue;
        ans += g[i].first;
        merge(arr,p.first,p.second);
    }

    cout << ans;
}