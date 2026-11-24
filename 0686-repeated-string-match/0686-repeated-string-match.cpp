class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = a;
        int cnt = 1;

        while (s.size() < b.size()) {
            s += a;
            cnt++;
        }

        if (s.find(b) != string::npos)
            return cnt;

        s += s;

        if (s.find(b) != string::npos)
            return cnt + 1;

        return -1;
    }
};