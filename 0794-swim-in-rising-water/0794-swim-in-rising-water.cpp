
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;

        int del_row[] = {-1, 0, 1, 0};
        int del_col[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int t = top[0];
            int r = top[1];
            int c = top[2];
            if (r == n - 1 && c == n - 1) return t;
            for (int i = 0; i < 4; i++) {
                int nr = r + del_row[i];
                int nc = c + del_col[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    pq.push({max(t, grid[nr][nc]), nr, nc});
                }
            }
        }

        return -1;
    }

};