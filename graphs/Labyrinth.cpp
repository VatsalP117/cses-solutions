#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin>>n>>m;
	vector<vector<char>> grid(n,vector<char>(m));
	int startRow,startCol;
	int endRow,endCol;
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        cin>>grid[i][j];
	        if(grid[i][j]=='A'){
	            startRow=i;
	            startCol=j;
	        }
	        else if(grid[i][j]=='B'){
	            endRow=i;
	            endCol=j;
	        }
	    }
	}
	vector<vector<int>> dist(n,vector<int>(m,1e8));
	dist[startRow][startCol]=0;
    queue<pair<int,pair<int,int>>> q;
	q.push({startRow,{startCol,0}});
	dist[startRow][startCol]=0;
	int dx[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
	   
	    
	while(!q.empty()){
	    int row=q.front().first;
	    int col=q.front().second.first;
	    int dis=q.front().second.second;
	    q.pop();
	    if(dis>dist[row][col]){
	        continue;
	    }
	     for(int i=0;i<4;i++){
	        int rr=row+dx[i];
	        int cc=col+dc[i];
	       
	        if(rr>=0 && rr<n && cc>=0 && cc<m && (grid[rr][cc]=='.' || grid[rr][cc]=='B') && dist[rr][cc]>1+dis){
	             dist[rr][cc]=1+dis;
	             q.push({rr,{cc,1+dis}});
	            }
	        }
	    
	    }
	    //now time to backtrack
	    int steps=dist[endRow][endCol];
	    if(steps>=1e8){
	        cout<<"NO"<<endl;
	        return 0;
	    }
	    cout<<"YES"<<endl;
	    cout<<steps<<endl;
	    vector<int> ans;
	    int row=endRow;
	    int col=endCol;
	    while(steps!=0){
	        for(int i=0;i<4;i++){
	            int rr=row+dx[i];
    	        int cc=col+dc[i];
    	       
    	        if(rr>=0 && rr<n && cc>=0 && cc<m && dist[rr][cc]<steps){
    	             steps--;
    	             row=rr;
    	             col=cc;
    	             ans.push_back(i);
    	             break;
    	        }
	        }
	    }
	 reverse(ans.begin(),ans.end());
	for(int a:ans){
	    if(a==0) cout<<'D';
	    if(a==1)cout<<'L';
	    if(a==2)cout<<'U';
	    if(a==3)cout<<'R';
	}
	return 0;
}
