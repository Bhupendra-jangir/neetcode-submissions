class Solution {
public:
    int m,n;
    int ans;
    int dr[4]  = {0,0,-1,1};
    int dc[4] = {-1,1,0,0};
    int dfs(int i,int j,vector<vector<int>>& grid){
        grid[i][j] = 0;
        int area = 1;
        for(int k = 0;k<4;k++){
            int nr = i + dr[k];
            int nc = j + dc[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc] == 1){
                area += dfs(nr,nc,grid);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m= grid.size();
        n = grid[0].size();
        ans = 0;
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == 1){
                    ans = max(ans,dfs(i,j,grid));
                }
            }   
        }
        return ans;
    }
};