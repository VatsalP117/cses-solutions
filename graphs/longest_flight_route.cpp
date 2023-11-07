#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(n+1);
	int a,b;
	for(int i=0;i<m;i++){
	    cin>>a>>b;
	    adj[a].push_back(b);
	}
	//input taken
	vector<int> dist(n+1,-1);
	vector<int> par(n+1);
	for(int i=0;i<=n;i++) par[i]=i;
	dist[1]=1;
	par[1]=1;
	priority_queue<pair<int,int>> pq;
	pq.push({1,1});
	while(!pq.empty()){
	    int node=pq.top().second;
	    int dis=pq.top().first;
	    pq.pop();
	    if(dis<dist[node]){
	        continue;
	    }
	    for(auto adjNode:adj[node]){
	        if(dis+1>dist[adjNode]){
	            pq.push({dis+1,adjNode});
	            dist[adjNode]=dis+1;
	            par[adjNode]=node;
	        }
	    }
	}
	if(par[n]==n){
	    cout<<"IMPOSSIBLE"<<endl;
	    return 0;
	}
	vector<int> path;
	int node=n;
	while(par[node]!=node){
	    path.push_back(node);
	    node=par[node];
	}
	path.push_back(1);
	if(path.size()!=dist[n]){
	    cout<<"IMPOSSIBLE"<<endl;
	    return 0;
	}
	cout<<dist[n]<<endl;
	for(int i=path.size()-1;i>=0;i--){
	    cout<<path[i]<<" ";
	}
	return 0;
}
