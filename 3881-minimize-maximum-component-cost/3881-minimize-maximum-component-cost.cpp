class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        DSU(int n) {
            parent.resize(n);
            for (int i = 0; i < n; ++i)
                parent[i] = i;
        }
        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        void unite(int x, int y) {
            parent[find(x)] = find(y);
        }
    };

    int minCost(int n, vector<vector<int>>& edges, int k) {
        int low = 0, high = 0, answer = -1;
        for (auto& edge : edges)
            high = max(high, edge[2]); 

        auto isValid = [&](int maxWeight) {
            DSU dsu(n);
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                if (w <= maxWeight)
                    dsu.unite(u, v);
            }

            unordered_set<int> components;
            for (int i = 0; i < n; ++i)
                components.insert(dsu.find(i));
            return components.size() <= k;
        };

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isValid(mid)) {
                answer = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;  
            }
        }

        return answer;
    }
};
