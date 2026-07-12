class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]=='1'){
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>> &grid, int r, int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]=='0'){
            return;
        }
        grid[r][c]='0';
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
        dfs(grid, r+1, c);
    }
};