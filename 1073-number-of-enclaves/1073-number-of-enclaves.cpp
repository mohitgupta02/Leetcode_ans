class Solution {
public:
    void dfs1(int row, int col, vector<vector<int>>& grid,
              vector<vector<int>>& vis, int n, int m, int drow[], int dcol[]) {
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs1(nrow, ncol, grid, vis, n, m,drow, dcol);
            } 
        }
    }


    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int n, int m, int& cnt,
             int drow[], int dcol[]) {
        cnt++;
        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                dfs(nrow, ncol, grid, vis, n, m, cnt, drow, dcol);
            }
        }
    }



    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int total = 0;
        int drow[] = {0, 0, -1, 1};
        int dcol[] = {1, -1, 0, 0};
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) {
                dfs1(i, 0, grid, vis, n, m, drow, dcol);
            }
            if (grid[i][m - 1] == 1) {
                dfs1(i, m - 1, grid, vis, n, m, drow, dcol);
            }
        }

        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) {
                dfs1(0, j, grid, vis, n, m, drow, dcol);
            }
            if (grid[n - 1][j] == 1) {
                dfs1(n - 1, j, grid, vis, n, m, drow, dcol);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] != 1 && grid[i][j] == 1) {
                    int cnt = 0;
                    dfs(i, j, grid, vis, n, m, cnt, drow, dcol);
                    total += cnt;
                }
            }
        }

        return total;
    }
};