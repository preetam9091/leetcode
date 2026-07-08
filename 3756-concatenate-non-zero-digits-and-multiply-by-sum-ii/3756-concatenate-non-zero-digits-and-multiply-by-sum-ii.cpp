#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        const int MOD = 1e9 + 7;
        
        // 1. Precompute powers of 10 modulo 10^9 + 7
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        
        // 2. Initialize prefix arrays
        vector<long long> sumD(n + 1, 0);
        vector<int> cntN0(n + 1, 0);
        vector<long long> p(n + 1, 0);
        
        // 3. Build the prefix arrays
        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            
            sumD[i + 1] = sumD[i] + digit;
            cntN0[i + 1] = cntN0[i] + (digit > 0 ? 1 : 0);
            
            if (digit > 0) {
                p[i + 1] = (p[i] * 10 + digit) % MOD;
            } else {
                p[i + 1] = p[i]; // Ignore zeros, carry forward the previous number
            }
        }
        
        // 4. Process queries in O(1) time each
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int left = q[0];
            int right = q[1];
            
            // Calculate total non-zero digits and digit sum in the current range
            int n0 = cntN0[right + 1] - cntN0[left];
            long long sd = sumD[right + 1] - sumD[left];
            
            // Mathematically extract the substring's concatenated number
            long long removedPrefix = (p[left] * pow10[n0]) % MOD;
            long long x = (p[right + 1] - removedPrefix + MOD) % MOD;
            
            // Multiply by the sum and push to answers
            ans.push_back((x * sd) % MOD);
        }
        
        return ans;
    }
};