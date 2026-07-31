class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long long area = 0;
        int minX = INT_MAX, minY = INT_MAX;
        int maxX = INT_MIN, maxY = INT_MIN;

        set<pair<int,int>> st;

        for (auto &r : rectangles) {
            minX = min(minX, r[0]);
            minY = min(minY, r[1]);
            maxX = max(maxX, r[2]);
            maxY = max(maxY, r[3]);

            area += 1LL * (r[2]-r[0]) * (r[3]-r[1]);

            pair<int,int> p[4] = {
                {r[0], r[1]}, {r[0], r[3]},
                {r[2], r[1]}, {r[2], r[3]}
            };

            for (auto &x : p) {
                if (st.count(x))
                    st.erase(x);
                else
                    st.insert(x);
            }
        }

        if (st.size() != 4) return false;

        if (!st.count({minX,minY}) ||
            !st.count({minX,maxY}) ||
            !st.count({maxX,minY}) ||
            !st.count({maxX,maxY}))
            return false;

        return area == 1LL * (maxX-minX) * (maxY-minY);
    }
};