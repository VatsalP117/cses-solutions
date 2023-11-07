#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<vector<char>> grid(n,vector<char>(n));
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        cin>>grid[i][j];
	    }
	}
	//input taken
	//ans: num ways to reach lower right i.e n-1,n-1 from 0,0
	vector<vector<int>> dp(n,vector<int>(n,0));
	//base case: only 1 way to reach elements in top row and 1st column
	for(int i=0;i<n;i++){
	    if(grid[i][0]=='*'){
            break;
        }
        dp[i][0]=1;
	}
    for(int i=0;i<n;i++){
	    if(grid[0][i]=='*'){
            break;
        }
        dp[0][i]=1;
	}
	//for (i,j) => you need ways to reach (i-1,j) and (i,j-1)
	//islie iterate i=> 0..n and j=>0..n 
	for(int i=1;i<n;i++){
	    for(int j=1;j<n;j++){
	        if(grid[i][j]=='*'){
	            dp[i][j]=0;
	        }
	        else {
                dp[i][j]+=(dp[i-1][j]+dp[i][j-1]);
                dp[i][j]%=MOD;
                }
	    }
	}
	cout<<dp[n-1][n-1]<<endl;
	return 0;
}
