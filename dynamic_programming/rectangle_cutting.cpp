#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int W,H;
	cin>>W>>H;
	int min_l=min(W,H);
	vector<vector<int>> dp(W+1,vector<int>(H+1));
	//dp[i][j]=k => means k cuts needed to make a rectangle of dimensions (i,j) into a square
	//initialize all already existing squares to value 0 in dp array 
    for(int w=0;w<=W;w++){
        for(int h=0;h<=H;h++){
            if(w==h){
                //already a square 
                dp[w][h]=0;
            }
            else{
                dp[w][h]=1e9;
                //now try cuts horizontally and vertically
                for(int i=1;i<=w-1;i++){
                    //i is the width of 1st rect of the two parts we cutting into so width of 2nd part = w-i
                    dp[w][h]=min(dp[w][h],dp[i][h]+dp[w-i][h]+1);
                }
                for(int i=1;i<=h-1;i++){
                    dp[w][h]=min(dp[w][h],dp[w][i]+dp[w][h-i]+1);
                }
        }
    }
    }
    cout<<dp[W][H]<<endl;
	return 0;
}
