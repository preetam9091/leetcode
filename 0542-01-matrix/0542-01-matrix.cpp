class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<vector<int>> dis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0) {vis[i][j]=1; q.push({{i, j}, 0});}
            }
        }
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int row = q.front().first.first;
                int col = q.front().first.second;
                for(int j=0; j<4; j++){
                    int r = row + dir[j][0];
                    int c = col + dir[j][1];
                    int num = q.front().second;
                    if(r>=0 && c>=0 && r<mat.size() && c<mat[0].size() && mat[r][c]==1){
                        mat[r][c]=0;
                        vis[r][c]=1;
                        dis[r][c]=num+1;
                        q.push({{r, c}, num+1});
                    }
                }                q.pop();
            }
        }
        return dis;

    }
};