class Solution {
public:
    class DSU {
    public:
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; ++i)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        bool unite(int x, int y) {
            int xr = find(x), yr = find(y);
            if (xr == yr) return false;
            if (rank[xr] < rank[yr]) parent[xr] = yr;
            else if (rank[xr] > rank[yr]) parent[yr] = xr;
            else {
                parent[yr] = xr;
                rank[xr]++;
            }
            return true;
        }
    };

    int minCost(int n, vector<vector<int>>& edges, int k) {
        if (k >= n) return 0;

        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        DSU dsu(n);
        int maxCost = 0;
        int edgesUsed = 0;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dsu.unite(u, v)) {
                maxCost = max(maxCost, w);
                edgesUsed++;
                if (edgesUsed == n - k) break;
            }
        }

        return maxCost;
    }
};
