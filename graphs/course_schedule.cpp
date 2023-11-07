#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(n+1);
	int a,b;
	vector<int> indegree(n+1,0);
	for(int i=0;i<m;i++){
	    cin>>a>>b;
	    adj[a].push_back(b);
	    //b ka pre req a hai
	    indegree[b]++;
	}
    queue<int> q;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            //means iska koi pre-req nahi hai
            q.push(i);
            
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto adjNode:adj[node]){
            indegree[adjNode]--;
            if(indegree[adjNode]==0){
                q.push(adjNode);
            }
        }
    }
    if(ans.size()!=n) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int a:ans) cout<<a<<" ";
    }
	return 0;
}
