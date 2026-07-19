class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26, 0);
        vector<bool> seen(26, false);
        string ans = "";
        
        for (int i = 0; i < s.length(); i++) {
            last[s[i] - 'a'] = i;
        }
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (seen[c - 'a']) continue;
            
            while (!ans.empty() && ans.back() > c && last[ans.back() - 'a'] > i) {
                seen[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            
            seen[c - 'a'] = true;
            ans.push_back(c);
        }
        
        return ans;
    }
};