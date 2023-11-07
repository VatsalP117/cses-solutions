// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        arr[i]=x;
    }
    //now real code of sliding window
    unordered_map<int,int> m;
    int count=0;
    int i=0;
    int j=0;
    long long res=0;
    
    while(j<n){
        m[arr[j]]++;
        if(m[arr[j]]==1){
            count++;
        }
        if(count>k){
            while(count>k){
                m[arr[i]]--;
                if(m[arr[i]]==0){
                    count--;
                }
                i++;
            }
        }
        res+=(j-i+1);
        j++;
    }
    cout<<res<<endl;
    return 0;

}