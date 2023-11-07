#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	//n = number of computers
	//m = number of exisiting connections
    vector<pair<int,int>> edges(m);
	int a,b;
	for(int i=0;i<m;i++){
	    cin>>a>>b;
	    edges[i]={a,b};
	 }
	 vector<vector<int>> adj(n+1);
	 for(auto it:edges){
	     adj[it.first].push_back(it.second);
	     adj[it.second].push_back(it.first);
	 }
	 queue<pair<int,int>> q;
	 vector<int> dist(n+1,1e8);
	 vector<int> parent(n+1);
	 for(int i=1;i<=n;i++)parent[i]=i;
	 q.push({1,1});//i.e you reached node 1 with 1 computer on the route
	 dist[1]=1;
	 while(!q.empty()){
	     int node=q.front().first;
	     int dis=q.front().second;
	     q.pop();
	     for(auto adjNode:adj[node]){
	         if(dis+1<dist[adjNode]){
	             q.push({adjNode,dis+1});
	             dist[adjNode]=dis+1;
	             parent[adjNode]=node;
	         }
	     }
	 }
	 if(parent[n]==n){
	     cout<<"IMPOSSIBLE"<<endl;
	 }
	 else{
	     //means you have a valid path
	     cout<<dist[n]<<endl;
	     vector<int> ans;
	     int node=n;
	     while(node!=1){
	         ans.push_back(node);
	         node=parent[node];
	     }
	     ans.push_back(1);
	     reverse(ans.begin(),ans.end());
	     for(int a:ans){
	         cout<<a<<" ";
	     }
	 }
	return 0;
}
