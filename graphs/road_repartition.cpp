#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    public: 
    vector<int> rank;
    vector<int> parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    
    int findUParent(int u){
        if(u==parent[u]) return u;
        else return findUParent(parent[u]);
    }
    
    void unionByRank(int u,int v){
        int pu=findUParent(u);
        int pv=findUParent(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<vector<int>> roads(m);
	int a,b,c;
	for(int i=0;i<m;i++){
	    cin>>a>>b>>c;
	    roads[i]={c,b,a};
	}
	sort(roads.begin(),roads.end());
	DisjointSet ds(n);
	long cost=0;
	for(auto it:roads){
	    int c=it[0];
	    int a=it[1];
	    int b=it[2];
	    if(ds.findUParent(a)!=ds.findUParent(b)){
	        ds.unionByRank(a,b);
	        cost+=c;
	    }
	}
	int numComponents=0;
	for(int i=1;i<=n;i++){
	    if(ds.parent[i]==i){
	        numComponents++;
	    }
	}
	if(numComponents>1){
	    cout<<"IMPOSSIBLE"<<endl;
	}
	else cout<<cost<<endl;
	return 0;
}
