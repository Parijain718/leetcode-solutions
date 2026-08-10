class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c){
        int n = grid.size();
        int m = grid[0].size();
        if(r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0){
            return 0;
        }
        grid[r][c] = 0;
        int area = 1;
        area += dfs(grid,r+1,c);
        area += dfs(grid,r-1,c);
        area += dfs(grid,r,c+1);
        area += dfs(grid,r,c-1);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    maxi = max(maxi,dfs(grid,i,j));
                }
            }
        }
        return maxi;
    }
};