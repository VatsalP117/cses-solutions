#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    public: 
    vector<int> rank;
    vector<int> parent;
    vector<int> compSize;
    DisjointSet(int n){
        rank.resize(n+1,0);
        compSize.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    
    int findUParent(int u){
        if(u==parent[u]) return u;
        else return findUParent(parent[u]);
    }
    
    int unionByRank(int u,int v){
        int pu=findUParent(u);
        int pv=findUParent(v);
        if(pu==pv) return 0;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
            compSize[pv]+=compSize[pu];
            return compSize[pv];
        }
        else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
            compSize[pu]+=compSize[pv];
            return compSize[pu];
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
            compSize[pu]+=compSize[pv];
            return compSize[pu];
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
	    cin>>a>>b;
	    roads[i]={a,b};
	}

	DisjointSet ds(n);
    int numComponents=n;
    int maxi=1;
	for(auto it:roads){
	
	    int a=it[0];
	    int b=it[1];
	    if(ds.findUParent(a)!=ds.findUParent(b)){
	        maxi=max(maxi,ds.unionByRank(a,b));
	        numComponents--;
	    }

	    cout<<numComponents<<" "<<maxi<<endl;
	}

	return 0;
}
