// Approach 
// input arr=_ _ _ _ _ where some values will be fixed, some will be not
//     say the nth position is not fiex i.e=0
//     [_ _ _ Y] 1, say we put 1 on the last placed index 
//     bacha hua [] should also be valid and Y can be either 1 or 2 for entire array to be valid
//     General case: [_ _ _ X-1] X, all the valid arrays of size N-1 having X-1 at last can be extended like this
//                   [_ _ _ X] X, (same as above)
//                   [_ _ _ X+1] X,

//     Dp state:
//     dp[i][x] => number of valid arrays consisiting of 1st i positions(i.e size=i) s.t at the ith position, we place the element x 

//     Ans:
//     valid array either ends in 1 or 2...M
//     so ans would be sum of all possibilities i.e dp(N,1)+dp(N,2)+dp(N,3)..+dp(N,M)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MOD=(int)1e9+7;
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	vector<vector<int>> dp(n,vector<int>(m+1,0));
	//base case
    if(arr[0]!=0){
        //to some fixed value hai which we cant change
        dp[0][arr[0]]=1;
    }
    else{
        //we can put any value in 0th index
        for(int last=1;last<=m;last++){
            dp[0][last]=1;
        }
    }
    //now start iterating
    for(int i=1;i<n;i++){
        for(int x=1;x<=m;x++){
            //what condition ki yaha pe x put kar sakte?
            //if 0 hai ya fir value hi khud x hai
            if(arr[i]==0 || arr[i]==x){
                dp[i][x]+=dp[i-1][x];
                dp[i][x]%=MOD;
                if(x>=2){
                    dp[i][x]+=dp[i-1][x-1];
                    dp[i][x]%=MOD;
                }
                if(x<m){
                    dp[i][x]+=dp[i-1][x+1];
                    dp[i][x]%=MOD;
                }
            }
            else dp[i][x]=0;
        }
    }
    int res=0;
    for(int last=1;last<=m;last++){
        res+=dp[n-1][last];
        res%=MOD;
    }
    cout<<res<<endl;
	return 0;
}
