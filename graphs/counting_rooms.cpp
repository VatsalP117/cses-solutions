#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void dfs(int row,int col,int n,int m,vector<vector<char>> &matrix,vector<vector<int>> &vis){
    vis[row][col]=1;
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    for(int i=0;i<4;i++){
        int rr=row+dx[i];
        int cc=col+dy[i];
        if(rr>=0 && rr<n && cc>=0 && cc<m && matrix[rr][cc]=='.' && vis[rr][cc]==0){
            dfs(rr,cc,n,m,matrix,vis);
        }
    }
}
int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	//n=height = number of rows
	//m=width= number of columns
	vector<vector<char>> matrix(n,vector<char>(m));
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        cin>>matrix[i][j];
	    }
	}
	//. = floor and #=wall
	//input taken
	//idea= room would be covered by walls on all sides bas done
	int res=0;
	vector<vector<int>> vis(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        if(matrix[i][j]=='.' && vis[i][j]==0){
	            res++;
	            dfs(i,j,n,m,matrix,vis);
	        }
	    }
	}
	cout<<res<<'\n';
	return 0;
}
