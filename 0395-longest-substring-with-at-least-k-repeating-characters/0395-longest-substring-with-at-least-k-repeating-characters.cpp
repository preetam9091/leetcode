class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;

        for (int target = 1; target <= 26; target++) {
            vector<int> cnt(26, 0);
            int l = 0, r = 0;
            int unique = 0;
            int atLeastK = 0;

            while (r < s.size()) {
                if (cnt[s[r]-'a']++ == 0)
                    unique++;
                if (cnt[s[r]-'a'] == k)
                    atLeastK++;
                r++;

                while (unique > target) {
                    if (cnt[s[l]-'a'] == k)
                        atLeastK--;
                    if (--cnt[s[l]-'a'] == 0)
                        unique--;
                    l++;
                }

                if (unique == target && unique == atLeastK)
                    ans = max(ans, r-l);
            }
        }

        return ans;
    }
};