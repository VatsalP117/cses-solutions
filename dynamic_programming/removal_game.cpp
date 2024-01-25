#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(int i,int j,int n,vector<int> &arr,vector<vector<ll>> &dp){
     if(i>=n || j>=n || i<0 || j<0 || i>j) return 0;
    if(i==j){
        //only one element so player 1 wil take it easy 
        return dp[i][j]=arr[i];
    }
   
    if(dp[i][j]!=-1)return dp[i][j];
    //either first pick or pick last 
    //after our move 2nd player will pick something such that our final score will be minimized
    ll pickFirst=arr[i]+min(solve(i+2,j,n,arr,dp),solve(i+1,j-1,n,arr,dp));
    ll pickLast=arr[j] + min(solve(i+1,j-1,n,arr,dp),solve(i,j-2,n,arr,dp));
    return dp[i][j]=max(pickFirst,pickLast);
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	vector<vector<ll>> dp(n,vector<ll>(n,-1));//dp[i][j]= maximum score of P1 if he plays first from arr[i] to arr[j]
	//final ans=dp[0][n-1]
	cout<<solve(0,n-1,n,arr,dp)<<endl;
	return 0;
}
