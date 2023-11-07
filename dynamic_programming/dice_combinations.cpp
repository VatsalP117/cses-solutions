#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Form 2
//Very similar to climbing stairs: numbers of ways to reach n if you can jump 1 or 2 steps etc ?
// Approach:
// what could be the last dice throw if you reached sum? i.e the last move
// say you were at sum-1 and you got a 1 => sum
// you were at sum-2 and you got a 2=> sum 
// .
// .
// you were at sum-6 and you got a 6 =>sum
// and all these ways will get added
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,0); //stores number of ways to reach a given value
    dp[1]=1;
    dp[0]=1;
    int mod=1e9+7;

    for(int i=2;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j>=0){
                dp[i] = (dp[i] + dp[i-j]) % mod;
            }
            else{
                break;
            }
        }
    }
   
    cout<<dp[n]%mod<<endl;
    return 0;

}