#include <iostream>
#include <bits/stdc++.h>
using namespace std;
static bool cmp(pair<int,int> &a,pair<int,int> &b){
    return a.second<b.second;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    int s,e;
    for(int i=0;i<n;i++){
        cin>>s>>e;
        arr.push_back({s,e});
    }
    sort(arr.begin(),arr.end(),cmp);
    //now sorted by end times
    int currEnd=0;
    int res=0;
    for(auto it:arr){
        if(it.first>=currEnd){
            res++;
            currEnd=it.second;
        }
    }
    cout<<res<<endl;
    return 0;
}