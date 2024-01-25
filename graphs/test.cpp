#include <bits/stdc++.h>
using namespace std;
#define pip pair<int,pair<int,int>>
 int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    char pathChar[]={'U','R','D','L'};
bool dfs(int row,int col,int steps,int n,int m,vector<vector<char>> &matrix,vector<vector<int>>&vis,vector<vector<int>>& distFromMonster,vector<char>&path){
    vis[row][col]=steps;
    if(steps>=distFromMonster[row][col]){
        return false;
    }
    if(row==n-1 || col==m-1 || row==0 || col==0){
        return true;
    }
    for(int i=0;i<4;i++){
            int rr=row+dx[i];
            int cc=col+dy[i];
            if(rr>=0 && rr<n && cc>=0 && cc<m && vis[rr][cc]>vis[row][col]+1 &&  matrix[rr][cc]=='.'){
                if(dfs(rr,cc,steps+1,n,m,matrix,vis,distFromMonster,path)){
                    path.push_back(pathChar[i]);
                    return true;
                }
                
            }
    }
    return false;

    
}
int main(){
    int n,m;
    cin>>n>>m;
    //n,m = height and width of map = number of rows, columns
    vector<vector<char>> matrix(n,vector<char>(m));
    int startRow,startCol;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>matrix[i][j];
        if(matrix[i][j]=='A'){
            startRow=i;
            startCol=j;
        }
    }
   }

    vector<vector<int>> distFromMonster(n,vector<int>(m,1e8));

    
    queue<pip> q;//{dist,{row,col}}
    //bfs to find min dist of all cells from any monster
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]=='M'){
                q.push({0,{i,j}});
                distFromMonster[i][j]=0;
            }
        }
    }
     while(q.empty()==false){
        int dis=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;
        q.pop();
        // if(dis>=distFromMonster[row][col]){
        //     continue;
        // }
        for(int i=0;i<4;i++){
            int rr=row+dx[i];
            int cc=col+dy[i];
            if(rr>=0 && rr<n && cc>=0 && cc<m && matrix[rr][cc]!='#' && distFromMonster[rr][cc]>1+dis){
                q.push({1+dis,{rr,cc}});
                distFromMonster[rr][cc]=1+dis;
            }
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,1e8));
    vector<char> path;
    //NOW START dfs from start and any cell is safe if and only if we can reach it in lesser number of steps than any monster can
    if(dfs(startRow,startCol,0,n,m,matrix,vis,distFromMonster,path)==true){
        //find path
        cout<<"YES"<<endl;
        reverse(path.begin(),path.end());
        cout<<path.size()<<endl;
        for(auto ch:path)cout<<ch;
    }
    else{
        cout<<"NO"<<endl;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<distFromMonster[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //   for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<vis[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //0 means in no team, 1 means team1 and 2 means team2

    
    return 0;
}