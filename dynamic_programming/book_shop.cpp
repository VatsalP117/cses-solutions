#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> price(n);
    vector<int> pages(n);
   
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    vector<vector<int>> dp(n,vector<int>(x+1,0));
    //dp[ind][sum]=> max number of pages you can buy by spending at most sum amount (can buy each book atmax one time)
    for(int sum=price[0];sum<=x;sum++){
        //since for money less than price of 1st book, you can read zero pages that is already the default value in dp
        dp[0][sum]=pages[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int sum=0;sum<=x;sum++){
            dp[ind][sum]+=dp[ind-1][sum];
            if(sum>=price[ind]){
                dp[ind][sum]=max(dp[ind][sum],pages[ind]+dp[ind-1][sum-price[ind]]);
            }
        }
    }
    cout<<dp[n-1][x]<<'\n';
    return 0;
}