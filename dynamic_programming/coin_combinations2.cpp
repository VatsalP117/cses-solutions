
//this is different from coin combinations 1 in the sense this isme same valueski permutations count nahi honi chaiye
//so for 2+4+3 we should only count it once and not 2+3+4, 4+2+3 etc again as well
// In questions related to distinct ordered ways, it generally involves a sorted sequence of the numbers available
// eg: coins ={2,3,5}
//     decide on how many 2 you need, how many 3 and how many 5
//     uske baad unko arrange karne ka sirf ek hi tarika hai => the sorted order


// This is back to form1, we are standing at some index and deciding kitni baar lena hai usko

//  In the previous problem, we tried out each coin for each possible sum value
// Here, we'll do the reverse, looping through all possible sum values (>=0 && <=x) for each coin i

// This essentially entails switching the order of the nested loops from the previous problem. Since we now loop over the coins before the weights, 
// we only go through the set of coins once, so it's impossible to create two combinations with the same set of coins ordered differently.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int main() {
	// your code goes here
	int n,x;
	cin>>n>>x;
	//n is number of coins and x is the required sum
	vector<int> coins(n);
	for(int i=0;i<n;i++){
	    cin>>coins[i];
	}
	//input taken now we start real code
	vector<vector<int>> dp(n,vector<int>(x+1,0));
	//basically dp[ind][sum]=>  number of ways needed to make sum using coins from 0..ind
	for(int sum=0;sum<=x;sum++){
	    if(sum%coins[0]==0){
	        dp[0][sum]=1;
	    }
	    else dp[0][sum]=0;
	}
	for(int ind=1;ind<n;ind++){
	    dp[ind][0]=1;//since only 1 way to make sum=0
	    for(int sum=1;sum<=x;sum++){
	        dp[ind][sum]+=dp[ind-1][sum];
            dp[ind][sum]%=MOD;
	        if(coins[ind]<=sum){
	            dp[ind][sum]+=dp[ind][sum-coins[ind]];
                dp[ind][sum]%=MOD;
	        }
	    }
	}
	cout<<dp[n-1][x]<<'\n';
	return 0;
}
