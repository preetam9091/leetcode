class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        vector<pair<int, int>> v = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        dis[0][0] = 1;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            auto it = pq.top();
pq.pop();

int weight = it.first;
int row = it.second.first;
int col = it.second.second;
if(weight > dis[row][col]) continue;
            for(int i=0; i<8; i++){
                if(row+v[i].first>=00 && row+v[i].first<n && col+v[i].second>=0 && col+v[i].second<n && grid[row+v[i].first][col+v[i].second]==0){
                    if(dis[row+v[i].first][col+v[i].second]>weight+1){
                    pq.push({weight +1, {row+v[i].first, col+v[i].second}});
                    dis[row+v[i].first][col+v[i].second]=weight+1;}
                }
            }

        }
        return dis[n-1][n-1] == INT_MAX ? -1 : dis[n-1][n-1];
    }
};