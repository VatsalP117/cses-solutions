#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
const int N=1e6+10;
    long long dp[N][2];
int solve(int n){
    if(dp[n][0]!=0){
          return (dp[n][0]+dp[n][1])%MOD;
    }
    
    
    //vector<vector<long long>> dp(n+1,vector<long long>(2,0));
    //dp[i][0]= (type 0)number of ways to fill till height i with the ith level as one block of width 2 
    //dp[i][1]= (type 1)number of ways to fill till height i with the ith level as 2 separate blocks of width 1 each
    //final ans = dp[n][0] + dp[n][1]
    dp[1][0]=1;
    dp[1][1]=1;
    for(int i=2;i<=n;i++){
        //case 1: we want ith level to be of type 0 i.e one block of width 2 
        //so we can either the continue all configurations joined till i-1 the level i.e = dp[i-1][0]
        //or we can create a new fresh block of 2 either on top of joined or separated configurations till i-th level 
        //dp[i][0]=dp[i-1][0] + (dp[i-1][0]+dp[i-1][1]);
        dp[i][0]=(2*dp[i-1][0])%MOD + dp[i-1][1];
        dp[i][0]%=MOD;
        
        //case 2: we want ith level to be of type 1 i.e 2 blocks of width 1 
        //4 things possible: extend left only, extend right only, extend both or extend none 
        //=4*separate(i-1)
        //or we can have two individual blocks on top of join(i-1) configurations
        dp[i][1]=(4*dp[i-1][1])%MOD + dp[i-1][0];
        dp[i][1]%=MOD;
        
    }
    return (dp[n][0]+dp[n][1])%MOD;
    
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	int n;
	memset(dp, 0, sizeof(dp));
	while(t--){
	    cin>>n;
	    cout<<solve(n)<<endl;
	}

	return 0;
}
