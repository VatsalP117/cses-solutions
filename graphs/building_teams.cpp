#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool dfs(int node,int color,vector<vector<int>> &adj,vector<int>&vis){
    vis[node]=color;
    int nextColor=2;
    if(color==2){
        nextColor=1;
    }
    for(auto adjNode:adj[node]){
        if(vis[adjNode]==0){
            if(dfs(adjNode,nextColor,adj,vis)==false) return false;
            
        }
        else if(vis[adjNode]==color){
                return false;
        }
    }
    return true;
}
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(n+1);
	int a,b;
	for(int i=0;i<m;i++){
	    cin>>a>>b;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}
	vector<int> vis(n+1,0);
	for(int i=1;i<=n;i++){
	    if(vis[i]==0){
	      if(dfs(i,1,adj,vis)==false){
	        cout<<"IMPOSSIBLE"<<endl;
	        return 0;
	        }  
	    }
	    
	}
	for(int i=1;i<=n;i++){
	    cout<<vis[i]<<" ";
	}
	return 0;
}
