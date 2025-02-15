#include<bits/stdc++.h>
using namespace std;
 
bool isValid(int i,int j,int n,int m,vector<vector<char>>& map){
    if(i<0 || i>=n || j<0 || j>=m || map[i][j]=='#') return false;
    return true;
}

//bfs approach
// int numberOfRooms(int n,int m,vector<vector<char>>& map) {
 
//     queue<pair<int,int>> q;
//     int count=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(map[i][j]=='#') continue;
//             count++;
//             map[i][j]='#';
//             q.push({i,j});
//             while(!q.empty()){
//                 int x=q.front().first;
//                 int y=q.front().second;
//                 q.pop();
//                 if(isValid(x+1,y,n,m,map)){
//                     map[x+1][y]='#';
//                     q.push({x+1,y});
//                 }
//                 if(isValid(x-1,y,n,m,map)){
//                     map[x-1][y]='#';
//                     q.push({x-1,y});
//                 }
//                 if(isValid(x,y+1,n,m,map)){
//                     map[x][y+1]='#';
//                     q.push({x,y+1});
//                 }
//                 if(isValid(x,y-1,n,m,map)){
//                     map[x][y-1]='#';
//                     q.push({x,y-1});
//                 }
//             }        
//         }
//     }
//     return count;
// }

void dfs(int i, int j, int n, int m, vector<vector<char>>& map) {
    map[i][j] = '#';  // Mark the current cell as visited
 
    // Directions: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
 
    for (int dir = 0; dir < 4; ++dir) {
        int newX = i + dx[dir];
        int newY = j + dy[dir];
 
        if (isValid(newX, newY, n, m, map)) {
            dfs(newX, newY, n, m, map);
        }
    }
}
 
// Count the number of distinct rooms
int numberOfRooms(int n, int m, vector<vector<char>>& map) {
    int count = 0;
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == '.') {
                ++count;           // Found a new room
                dfs(i, j, n, m, map);  // Explore the entire room
            }
        }
    }
 
    return count;
}
 
int main(){
 
    int n,m;
    cin>>n>>m;
    vector<vector<char>> map(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
 
    cout << numberOfRooms(n,m,map) << endl;
 
    return 0;
}