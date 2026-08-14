class Solution {
public:
    int dr[4] = {0,0,-1,1};
    int dc[4] = {-1,1,0,0};
    int m,n;
    void bfs(int i,int j,vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '0';
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            for(int k=0;k<4;k++){
                int newr = row+dr[k];
                int newc = col+dc[k];
                if(newr<m && newr>=0 && newc>=0 && newc<n && 
                        grid[newr][newc]=='1'){
                    q.push({newr,newc});
                    grid[newr][newc] = '0';

                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid[0].size();
        m = grid.size();
        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};