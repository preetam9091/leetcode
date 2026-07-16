class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        vector<int> dis(n+1, INT_MAX);
        for(auto v : times){
            adj[v[0]].push_back({v[2], v[1]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[k]=0;
        pq.push({0, k});
        while(!pq.empty()){
            int node = pq.top().second;
            int weight = pq.top().first;
                       pq.pop();
            if(weight>dis[node]) continue;
 
            for(auto v : adj[node]){
                int wt = v.first;
int nd = v.second;

if(weight + wt < dis[nd]) {
    dis[nd] = weight + wt;
    pq.push({dis[nd], nd});
}
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
    if(dis[i] == INT_MAX) return -1;
    ans = max(ans, dis[i]);
}
        return ans;
    }
};