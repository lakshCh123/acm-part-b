#include <bits/stdc++.h>
using namespace std;
int delRow[4]={1,0,-1,0};
int delCol[4]={0,1,0,-1};

void bfs(int x,int y,vector<vector<char>> &grid,vector<vector<int>>& visited){
queue<pair<int,int>> q;
visited[x][y]=1;
q.push({x,y});
while(!q.empty()){
    int size= q.size();
for (int j=0;j<size;j++){
x =q.front().first;
y=q.front().second;
q.pop();
for (int i=0;i<4;i++){
    int nrow = x+delRow[i];
    int ncol =y+delCol[i];
    if (nrow>=0&&nrow<grid.size()&&ncol>=0&&ncol<grid[0].size()){
        if (!visited[nrow][ncol]&&grid[nrow][ncol]=='.'){
            visited[nrow][ncol]=1;
             q.push({nrow,ncol});
        }
    }
}
}
}
}
int solve(int n ,vector<vector<char>> &grid,vector<vector<int>>& visited){
int ans =0;
    for (int i=0;i<grid.size();i++){
    for (int j=0;j<grid[0].size();j++){
        if (!visited[i][j]&&grid[i][j]=='.') {
            ans++;
            bfs( i, j, grid,visited);
        }
    }
}
return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    vector<vector<int>> visited(n,vector<int>(m,0));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) cin>>grid[i][j];
    }
    cout<<solve( n ,grid,visited)<<endl;
}