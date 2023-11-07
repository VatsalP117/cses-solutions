#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,int> p;
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m; 
	//n= number of cities
	//m= number of flights
	int a,b,c;
	vector<vector<pair<int,int>>> adj(n+1);
	for(int i=0;i<m;i++){
	    cin>>a>>b>>c;
	    adj[a].push_back({b,c});
	}
	//input taken here we go!
	vector<long long> dist(n+1,LLONG_MAX);
	priority_queue<p,vector<p>,greater<p>> pq; //min heap stores {dist,node}	
	pq.push({0,1});//can reach node 1(src) with distance=0
	dist[1]=0;
	while(!pq.empty()){
	    int node=pq.top().second;
	    long long dis=pq.top().first;
	    
	    pq.pop();
	    if(dis>dist[node]){
	        continue;
	    }
	    for(auto it:adj[node]){
	        int adjNode=it.first;
	        int edW=it.second;
	        if(dis+edW<dist[adjNode]){
	            //means you found a better path to pq mai daal do
	            dist[adjNode]=dis+edW;
	            pq.push({dis+edW,adjNode});
	        }
	    }
	}
	for(int i=1;i<=n;i++){
	    cout<<dist[i]<<" ";
	}
	return 0;
}
