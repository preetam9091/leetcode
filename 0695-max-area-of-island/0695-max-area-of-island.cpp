class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(), max = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int ct = 0;
                dfs(grid, i, j, ct, max);
            }
        }
        return max;
    }
    void dfs(vector<vector<int>> &grid, int r, int c, int &ct, int &max){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]==0){
            return;
        }
        ct++;
        if(ct>max) max = ct;
        grid[r][c]=0;
        dfs(grid, r, c+1, ct, max);
        dfs(grid, r, c-1, ct, max);
        dfs(grid, r+1, c, ct, max);
        dfs(grid, r-1, c, ct, max);

    }
};