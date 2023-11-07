#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//once again, same form 2 approach
//sum reach karne you could have reached from sum-x in the last move,where x is some coin value
//THIS is coin combinations 1: isme 2+2+3 and 2+3+2 are counted differently i.e permutations alag se counted
long long dp[1000100];

const int MOD = (int)1e9 + 7;
int main() {
	// your code goes here
	int n,x;
	cin>>n>>x;
	int y;
	vector<int> coins(n);
	for(int i=0;i<n;i++){
	    cin>>coins[i];
	}
    
	//n is number of coins and x is sum to be achieved
	//if you reach sum, you could have done that by being at sum-x and then picking coin x =>sum, where x is some coin value
    for(int i=0;i<=x;i++){
        if(i==0){
            dp[i]=1;
            //since only one way to make sum=0, do nothing 
        }
        else{
            dp[i]=0;
            for(int coin:coins){
                if(i-coin>=0){
                    dp[i]+=dp[i-coin];
                     dp[i]%=MOD;
                }
                
            }
        }
    }
	
	 cout<<dp[x]<<'\n';
	return 0;
}
