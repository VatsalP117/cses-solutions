#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//for there to be some ans, there must be a cycle in the graph
    //other ans would be IMPOSSIBLE
    //how to detect cycle?
    // using dfs, if you find some adjacent node as not visited, uska dfs kardo
    //if its visited and not the parent node (parent=jisne apne ko dfs call karke bulaya) then its a cycle
    //that already visited node can be called start point of cycle and this node as end

int cycleStart;
int cycleEnd;
//isme cycle ka start end store kar lenge
bool dfs(int node,int par,vector<vector<int>> &adj,vector<int> &vis,vector<int> &parent){
    vis[node]=1;
    parent[node]=par;//will be used to backtrack and retrive cycle 
    for(auto adjNode:adj[node]){
        if(adjNode==par){
            continue;
        }
        if(vis[adjNode]==1){
            //cycle found 
            cycleStart=adjNode;
            cycleEnd=node;
            return true;
        }
        else{
            if(dfs(adjNode,node,adj,vis,parent)==true){
                return true;
            }
        }
    }
    return false;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //input taken
    vector<int> vis(n+1,0);
    vector<int> parent(n+1,-1);
    
    bool isCycle=false;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(dfs(i,-1,adj,vis,parent)){
                //-1 bas dummy parent value
                //true will be return if cycle found to aage dhundhne ka zarurat nahi
                isCycle=true;
                break;
            }
        }
    }
    if(isCycle==false){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    //yaha tak code aa gya means cycle to mil gayi so backtrack from end 
    int node=cycleEnd;
    vector<int> ans;
    int cities=2;
    ans.push_back(cycleStart);
    while(node!=cycleStart){
        ans.push_back(node);
        node=parent[node];
        cities++;
    }
    ans.push_back(cycleStart);
    reverse(ans.begin(),ans.end());
    cout<<cities<<endl;
    for(int a:ans)cout<<a<<" ";
	return 0;
}
