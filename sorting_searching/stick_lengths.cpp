#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    int l;
    for(int i=0;i<n;i++){
        cin>>l;
        arr.push_back(l);
    }
    sort(arr.begin(),arr.end());
    int mid=arr[n/2]; //median
    //idea is to move everyone towards the median
    long long res=0;
    for(int i=0;i<n;i++){
        res+=abs(mid-arr[i]);
    }
    cout<<res<<endl;
    return 0;
}