#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> arr;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        if(arr[i]>=x){
            continue;
        }
        if(m.find(x-arr[i])!=m.end()){
            cout<<m[x-arr[i]]+1<<" "<<i+1<<endl;
            return 0;
        }
        m[arr[i]]=i;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}