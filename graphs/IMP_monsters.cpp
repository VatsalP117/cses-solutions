#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool dfs(int row,int col,int n,int m,int steps,vector<vector<char>> &grid,vector<vector<int>> &vis,vector<vector<int>> &dist,vector<int> &ans){
    //vis is actually distance matrix for our dfs calls
    if(dist[row][col]<=steps){
        return false;
    }
    if(row==n-1 || col==m-1 || row==0 || col==0){
        return true;
    }
    
    
    	int dx[]={-1,0,1,0};
	    int dc[]={0,1,0,-1};
	    for(int i=0;i<4;i++){
	        int rr=row+dx[i];
	        int cc=col+dc[i];
	       
	        if(rr>=0 && rr<n && cc>=0 && cc<m && grid[rr][cc]=='.' && vis[rr][cc]>vis[row][col]+1){
	             vis[rr][cc]=vis[row][col]+1;
	            if(dfs(rr,cc,n,m,steps+1,grid,vis,dist,ans)){
	                ans.push_back(i);
	                return true;
	            }
	        }
	    }
    return false;
}
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<vector<char>> grid(n,vector<char>(m));
	vector<vector<int>> dist(n,vector<int>(m,1e8));
	queue<pair<int,pair<int,int>>> q;
	int startRow,startCol;
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        cin>>grid[i][j];
	        if(grid[i][j]=='M'){
	            dist[i][j]=0;
	            q.push({i,{j,0}});
	        }
	        else if(grid[i][j]=='A'){
	            startRow=i;
	            startCol=j;
	        }
	    }
	}
	//multi-source bfs time bitches
	while(!q.empty()){
	    int row=q.front().first;
	    int col=q.front().second.first;
	    int d=q.front().second.second;
	    q.pop();
	    int dx[]={-1,0,1,0};
	    int dc[]={0,1,0,-1};
	    for(int i=0;i<4;i++){
	        int rr=row+dx[i];
	        int cc=col+dc[i];
	        if(rr>=0 && rr<n && cc>=0 && cc<m && (grid[rr][cc]=='.' || grid[rr][cc]=='A') && dist[rr][cc]>1+d){
	            dist[rr][cc]=1+d;
	            q.push({rr,{cc,1+d}});
	        }
	    }
	    
	}
	//dist matrix made

	vector<vector<int>> vis(n,vector<int>(m,1e8));
	vector<int> ans;
	vis[startRow][startCol]=0;
	if(dfs(startRow,startCol,n,m,0,grid,vis,dist,ans)==false){
	    cout<<"NO"<<endl;

	    return 0;
	}
		
	cout<<"YES"<<endl;
	cout<<ans.size()<<endl;
	reverse(ans.begin(),ans.end());
	for(int a:ans){
	    if(a==0)cout<<'U';
	    if(a==1)cout<<'R';
	    if(a==2)cout<<'D';
	    if(a==3)cout<<'L';
	}
	return 0;
}
