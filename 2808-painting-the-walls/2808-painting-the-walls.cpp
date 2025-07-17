class Solution {
public:
    int dp[501][501];
    int solve(vector<int>&cost, vector<int>&time, int n , int curr){
        if(n <= 0) return 0;
        if(curr >= cost.size()) return 1e9;
        if(dp[curr][n] != -1){
            return dp[curr][n];
        }

        return dp[curr][n] =min((cost[curr] + solve(cost,time,n - 1 - time[curr],curr+1)), solve(cost,time,n,curr+1));

    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp,-1,sizeof(dp));
        int n = cost.size();
        return solve(cost,time,n,0);   
    }
};