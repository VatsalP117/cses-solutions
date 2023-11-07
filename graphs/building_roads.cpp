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
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int u){
        if(u==parent[u]) return u;
        else return findUPar(parent[u]);
    }
    void unionByRank(int u,int v){
        int pu=findUPar(u);
        int pv=findUPar(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            //pu ko parent bana denge pv ko
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            //equal
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	//n = number of cities
	//m = number of already existing roads
	vector<pair<int,int>> roads(m);
	int a,b;
	for(int i=0;i<m;i++){
	    cin>>a>>b;
	    roads[i]={a,b};
	}
	//atmost one road between 2 cities 
	int res=0;
	
	DisjointSet ds(n);
	for(auto it:roads){
	    ds.unionByRank(it.first,it.second);
	}
	vector<int> components;
	for(int i=1;i<=n;i++){
	    if(ds.parent[i]==i){
	        res++;
	        components.push_back(i);
	    }
	}
	cout<<res-1<<endl;
	if(res>1){
	    for(int i=1;i<components.size();i++){
	        cout<<components[0]<<" "<<components[i]<<'\n';
	    }
	}
	return 0;
}
