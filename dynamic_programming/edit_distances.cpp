#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(int i,int j,string &s,string &t,vector<vector<int>> &dp){
    //base lite
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    //match
    if(s[i]==t[j]){
        return dp[i][j]=solve(i-1,j-1,s,t,dp);
    }
    else{
        return dp[i][j]=1+min(solve(i-1,j-1,s,t,dp),min(solve(i,j-1,s,t,dp),solve(i-1,j,s,t,dp)));
    }
}
int main() {
	// your code goes here
	string s,t;
	cin>>s>>t;
	int n=s.size();
	int m=t.size();
	vector<vector<int>> dp(n,vector<int>(m,-1));
	//convert s to t 
	cout<<solve(n-1,m-1,s,t,dp);
	return 0;
}
