#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Approach 1 (Form 1)
// Again go similar to dice combinations
// dp[sum] = min number of coins to make sum 
// to last move kya hoga
// you can be at sum-x and you get x => sum, where x belongs to the coins array
#include <iostream>
using namespace std;
int dp[1000100];
int coins[101];
int main() {
	// your code goes here
	int n,x;
	cin>>n>>x;
	int y;
	for(int i=0;i<n;i++){
	    cin>>y;
	    coins[i]=y;
	}
	//n is number of coins and x is sum to be achieved
	for(int i=0;i<=x;i++){
	    //base
	    if(i==0){
	        dp[i]=0; //since no coins required to make sum 0
	    }
	    else{
	        dp[i]=1e7;
	        //try all sum-x combos where x belongs to possible coins
	        for(int coin:coins){
	            if(i-coin>=0){
	                dp[i]=min(dp[i],1+dp[i-coin]);
	            }
	        }
	    }
	}
	if(dp[x]>=1e7)cout<<-1<<endl;
	else cout<<dp[x]<<endl;
	return 0;
}






//Approach 2
//Standard Form1 (pick/not pick)
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
    vector<vector<int>> dp(n,vector<int>(x+1,1e7));
    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }
    //base case for i=0;
    for(int sum=1;sum<=x;sum++){
        if(sum%arr[0]==0){
            dp[0][sum]=sum/arr[0];
        }
    }
    //good to go now
    for(int i=1;i<n;i++){
        //iterate for all sum values
        for(int sum=1;sum<=x;sum++){
                dp[i][sum]=dp[i-1][sum];
                if(arr[i]<=sum){
                    dp[i][sum]=min(dp[i][sum],1+dp[i][sum-arr[i]]);
                }
        }
    }
    if(dp[n-1][x]>=1e7){
        cout<<-1<<endl;
    }
    else{
        cout<<dp[n-1][x]<<endl;
    }
    return 0;
}