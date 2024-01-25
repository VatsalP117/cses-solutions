#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	int MAX_SUM=n*1000;//since each element can be at max 1000 
	vector<int> coins(n);
	for(int i=0;i<n;i++){
	    cin>>coins[i];
	}
	vector<vector<bool>> dp(n+1,vector<bool>(MAX_SUM+1,false));
	//dp[i][x]=true means we can create sum 'x' using i coins
	dp[0][0]=true;
	//idea 1: if we can create a sum x using i coins,we can also create the same sum using more than i coins 
	//idea 2: if current coin value =2 for eg and we can create sum x using i-1 coins, this implies we can create sum x+2 using i coins
    for(int i=0;i<n;i++){
        int num_coins=i+1;
        for(int sum=0;sum<=MAX_SUM;sum++){
            dp[num_coins][sum]=dp[num_coins-1][sum];//idea 1 
            int prev_sum=sum-coins[i];
            if(prev_sum>=0 && dp[num_coins-1][prev_sum]==true){
                dp[num_coins][sum]=true;
            }
        }
    }
    vector<int> ans;
    for(int sum=1;sum<=MAX_SUM;sum++){
        if(dp[n][sum]){
            ans.push_back(sum);
        }
    }
    cout<<ans.size()<<endl;
    for(int a:ans)cout<<a<<" ";
    return 0;
}
