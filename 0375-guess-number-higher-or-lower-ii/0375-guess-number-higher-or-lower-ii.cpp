class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int len = 2; len <= n; ++len) {
            for (int start = 1; start <= n - len + 1; ++start) {
                int end = start + len - 1;
                int min_res = INT_MAX;
                for (int piv = start; piv < end; ++piv) {
                    int res = piv + max(dp[start][piv - 1], dp[piv + 1][end]);
                    min_res = min(min_res, res);
                }
                dp[start][end] = min_res;
            }
        }
        return dp[1][n];
    }
};