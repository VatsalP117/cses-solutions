#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dfs(int node,vector<int> &subtreeSize,vector<vector<int>> &adj){
    if(node==NULL) return 0;
    subtreeSize[node]=0;
    for(auto adjNode:adj[node]){
        //ab iske subordinates ke under mai kitne employees hai vo bhi pata karo
        subtreeSize[node]+=dfs(adjNode,subtreeSize,adj);
    }
    return 1+subtreeSize[node];
}
int main() {
	// your code goes here
	int n;//number of employees => number of nodes
	cin>>n;
	//1 is the general director of company
	vector<vector<int>> adj(n+1);
	int boss;
	for(int i=0;i<n-1;i++){
	    cin>>boss;
	    //so boss is the boss of i+2 th employee (o index se 1 lene aur 1 to gen director hai to vo skip)
	    adj[boss].push_back(i+2);
	}
	vector<int> subtreeSize(n+1,0);
	dfs(1,subtreeSize,adj);
	for(int i=1;i<=n;i++)cout<<subtreeSize[i]<<" ";
	return 0;
}
