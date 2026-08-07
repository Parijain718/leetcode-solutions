class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c){
        int n = grid.size();
        int m = grid[0].size();
        if(r < 0 || c < 0 || r >= n ||  c>=m || grid[r][c] == '0' ){
            return;
        }
        grid[r][c] = '0'; 
        dfs(grid,r+1,c);
        dfs(grid,r-1,c);
        dfs(grid,r,c+1);
        dfs(grid,r,c-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        for(int i = 0 ;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid,i,j);
                }
            }
        }
        return islands;
    }
};