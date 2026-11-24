class Solution {
public:
    vector<int> p;

    int find(int x) {
        if (p[x] == x) return x;
        return p[x] = find(p[x]);
    }

    vector<int> findRedundantDirectedConnection(
        vector<vector<int>>& edges) {

        int n = edges.size();
        vector<int> par(n + 1, 0);
        vector<int> a, b;
        int skip = -1;

        for (int i = 0; i < n; i++) {
            int u = edges[i][0], v = edges[i][1];

            if (par[v]) {
                a = {par[v], v};
                b = {u, v};
                skip = i;
            } else {
                par[v] = u;
            }
        }

        p.resize(n + 1);

        for (int i = 0; i <= n; i++)
            p[i] = i;

        for (int i = 0; i < n; i++) {
            if (i == skip) continue;

            int u = find(edges[i][0]);
            int v = find(edges[i][1]);

            if (u == v) {
                if (a.empty()) return edges[i];
                return a;
            }

            p[v] = u;
        }

        return b;
    }
};