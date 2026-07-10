#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {nums[i], i};
        }
        
        sort(pairs.begin(), pairs.end());
        
        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            pos[pairs[i].second] = i;
        }
        
        int LOG = 20; 
        vector<vector<int>> up(n, vector<int>(LOG));
        
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j + 1 < n && pairs[j + 1].first - pairs[i].first <= maxDiff) {
                j++;
            }
            up[i][0] = j;
        }
        
        for (int k = 1; k < LOG; ++k) {
            for (int i = 0; i < n; ++i) {
                up[i][k] = up[up[i][k-1]][k-1];
            }
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            
            int start = pos[u];
            int target = pos[v];
            
            if (start > target) {
                swap(start, target);
            }
            
            if (start == target) {
                ans.push_back(0);
                continue;
            }
            
            if (up[start][LOG - 1] < target) {
                ans.push_back(-1);
                continue;
            }
            
            int steps = 0;
            int curr = start;
            for (int k = LOG - 1; k >= 0; --k) {
                if (up[curr][k] < target) {
                    curr = up[curr][k];
                    steps += (1 << k);
                }
            }
            
            ans.push_back(steps + 1);
        }
        
        return ans;
    }
};