class Solution {
public:

    void dfs(int row ,int col, vector<vector<int>>&vis, vector<vector<char>>&board,int drow[],int dcol[]){
        vis[row][col]=1;
        int n = board[0].size();
        int m = board.size();
        for(int i =0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow>=0 && nrow<m && ncol >=0 && ncol < n && board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                dfs(nrow,ncol,vis,board,drow,dcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,1,-1};
        for(int j =0;j<n;j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0,j,vis,board,drow,dcol);
            }
            if(!vis[m-1][j] && board[m-1][j]=='O'){   
                dfs(m-1,j,vis,board,drow,dcol);
            }
        }
        for(int i =0;i<m;i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,vis,board,drow,dcol);
            }
            if(!vis[i][n-1] && board[i][n-1]=='O'){
                dfs(i,n-1,vis,board,drow,dcol);
            }
        }
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};