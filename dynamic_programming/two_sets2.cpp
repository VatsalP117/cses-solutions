// This is a 0-1 knapsack in disguise. If we are to have two subsets of equal sum, they must sum to half the total sum each.
//  This means if the total sum n(n+1)2
//  is odd, the answer is zero (no possibilities). Otherwise we run 0-1 knapsack to get the number of ways to reach n(n+1)4
//  using subsets of the numbers 1..n-1. Why n-1? Because by only considering numbers up to n-1, we always put n in the second set,
//   and therefore only count each pair of sets once (otherwise we count every pair of sets twice).
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int main() {
	// your code goes here
	long long n;
	cin>>n;
	long long totSum=(n)*(n+1)/2;
	if(totSum%2==1){
	    cout<<0<<endl;
	    return 0;
	}
	long long reqSum=totSum/2;
	//decide on how many times to take a number from 1..n bas fir to aa hi gya ans 
	vector<vector<long long>> dp(n+1,vector<long long>(reqSum+1,0));
	dp[1][0]=1;
	dp[1][1]=1;
	for(long i=2;i<n;i++){
	    dp[i][0]=1;
	    for(long long sum=1;sum<=reqSum;sum++){
	        dp[i][sum]+=dp[i-1][sum];
	        dp[i][sum]%=MOD;
	        if(i<=sum){
	            dp[i][sum]+=dp[i-1][sum-i];
	            dp[i][sum]%=MOD;
	        }
	    }
	}
	cout<<dp[n-1][reqSum]<<endl;
	return 0;
}
