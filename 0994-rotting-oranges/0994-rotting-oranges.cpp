class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size(), minutes=0;
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==2) q.push({i, j});
                if(grid[i][j]==1) fresh++;
            }
        }
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int n = q.size();
            while(n--){
                auto curr = q.front();
                q.pop();
                int r = curr.first, c = curr.second;
                for(auto &dir : dir){
                    int row = r + dir.first;
                    int col = c +dir.second;
                    if(row>=0 && col>=0 && row<grid.size() && col<grid[0].size() && grid[row][col]==1){
                        grid[row][col]=2;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }
            if(!q.empty()) {
                minutes++;
            }
        }
        if(fresh>0) return -1;
        return minutes;
       
    }
};