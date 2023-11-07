#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Form 2
// Path/Sequence of moves etc => always Form 2
//How?
// dp[num]= min number of moves from num to 0
// dp[num]=min (dp[num-d]+1) where d is some digit in num
set<int> find_digit(int num){
    
    set<int> ans;
    
    while(num>0){
        ans.insert(num%10);
        num=num/10;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,1e8);
    //dp[num]=>number of moves from num to 0
    for(int i=0;i<=n;i++){
        if(i==0){
            dp[i]=0;
        }
        else{
            for(auto d:find_digit(i)){
                dp[i]=min(dp[i],1+dp[i-d]);
                
            }
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}