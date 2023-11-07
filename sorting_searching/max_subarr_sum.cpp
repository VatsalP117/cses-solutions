#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    long long curr=arr[0];
    long long res=arr[0];
    for(int i=1;i<n;i++){
        if(curr>=0){
            //means prev subarr sum was +ve to we should join these guys , if not start our own subarray
            curr+=arr[i];
            
        }
        else{
            curr=arr[i];
            
        }
        res=max(res,curr);
    }
    cout<<res<<endl;
    return 0;
}