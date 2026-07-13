class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            if(grid[i][0]==1){
                q.push({i, 0}); vis[i][0]=1; grid[i][0]=0;
            }
            if(grid[i][n-1]==1){
                q.push({i, n-1}); vis[i][n-1]=1; grid[i][n-1]=0;
            }
        }
        for(int i=0; i<n; i++){
            if(grid[0][i]==1){
                q.push({0, i}); vis[0][i]=1; grid[0][i]=0;
            }
            if(grid[m-1][i]==1){
                q.push({m-1, i}); vis[m-1][i]=1; grid[m-1][i]=0;
            }
        }
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                if(r>0 && c>0 && r<grid.size() && c<grid[0].size() && grid[r][c]==1 && vis[r][c]==0){
                    q.push({r, c});
                    vis[r][c]=1; grid[r][c]=0;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};