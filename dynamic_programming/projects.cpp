#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MP make_pair
const int INF=1000000000;
int main() {
	// your code goes here
	int n;
	cin>>n;
	pair<int,pair<int,int>> projects[n];
	int a,b,c;
	for(int i=0;i<n;i++){
	    cin>>a>>b>>c;
	    projects[i]=MP(a,MP(b,c));
	}
	sort(projects,projects+n);//sorted by start times
	//idea:
	//0-1 knapsack jaisa hi hai you either take it or not
	//if you do take it, the next project you can take would be jiska start time > apna end time 
	//iske liye lower bound ka use karenge
	vector<long long> dp(n+1,0);
	for(int i=n;i>=0;i--){
	    if(i==n){
	        //base case
	        dp[n]=0;
	    }
	    else{
	        dp[i]=dp[i+1];//not take
	        //but if you do take it? find the index jiska start > apna end 
	        int nextVal=projects[i].second.first;//apna end time
	        auto ind=upper_bound(projects,projects+n,MP(nextVal,MP(INF,INF)))-projects;
	        dp[i]=max(dp[i],projects[i].second.second+dp[ind]);
	        
	    }
	}
	cout<<dp[0]<<endl;
	return 0;
}
