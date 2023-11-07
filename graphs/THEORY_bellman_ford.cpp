// Applicable only in directed graphs
// helps to detect negative cycles

// 1-2(undirected) can be converted as 1->2 and 2->1 (directed) bellman ford lagane


// Algo:
// Saari edges leke rakhdo (in any order)
// Relax all the edges n-1 times sequentially
// Relax?  Perform this operation on every edge
// if(dist[u]+wt<dist[v]){
//     dist[v]=dist[u]+wt
// }
// isko bolte hai relax karna i.e koi ek shorter path mil gya node v tk pahochne

// on nth iteration , relaxation is done and distance firse reduce hua to negative cycle exists
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V,1e8); //1e8 means not reached yet
        dist[S]=0;
        //relaxation on all edges n-1 times
        for(int i=0;i<V-1;i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        //now check and try to relax nth time
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                  //negative cycle
                  return vector<int>(1,-1); 
            }
        }
        return dist;
    }