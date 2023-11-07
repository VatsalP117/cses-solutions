//ONLY POSITIVE NUMBERS
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr,int x){
    //returns number of subarrays with sum atmost x
    int n=arr.size();
    int i=0;
    int j=0;
    long res=0,sum=0;
    while(j<n){
        sum+=arr[j];
        if(sum>x){
            while(sum>x){
                sum-=arr[i];
                i++;
            }
        }
        res+=(j-i+1);
        j++;
    }
    return res;
}
int main() {
    // Write C++ code here
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    int y;
    for(int i=0;i<n;i++){
        cin>>y;
        arr[i]=y;
    }
    cout<<solve(arr,x)-solve(arr,x-1)<<endl;
    return 0;
}