class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>&grid,vector<vector<int>>&vis){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col= q.front().second;
            q.pop();
            int deltarow[] = {-1,1,0,0};
            int deltacol[] = {0,0,-1,1};
            for(int i =0;i<4;i++){
                    int newr = row + deltarow[i];
                    int newc = col + deltacol[i];

                    if(newr >=0 && newr <n && newc >= 0 && newc <m && grid[newr][newc] == '1' && !vis[newr][newc]){
                        vis[newr][newc] =1;
                        q.push({newr,newc});
                    }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int row =0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row,col,grid,vis);
                }
            }
        }
        return cnt;
    }
};