class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount +1,1e9));
        
        for(int i=0;i<=n;++i) dp[i][0]=0;

        for(int i =n-1;i>=0;--i){
            for(int sum =0;sum <= amount;++sum){
                int notTake = dp[i+1][sum];
                int take= 1e9;
                if(sum >= coins[i]){
                    take = 1 + dp[i][sum-coins[i]];
                }
                dp[i][sum] = min(take , notTake);
            }
        }
        return dp[0][amount] >= 1e9 ? -1:dp[0][amount];
    }   
};