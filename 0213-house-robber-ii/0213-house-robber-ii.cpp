class Solution {
public:
    int solve(int i , vector<int>& nums,int n,vector<int>& dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int steal = nums[i] + solve(i+2,nums,n,dp);
        int skip = solve(i+1,nums,n,dp);

        return dp[i] = max(steal,skip);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n+1,-1);
        int ans1=solve(0,nums,n-1,dp);
        vector<int>dp2(n+1,-1);
        int ans2 = solve(1,nums,n,dp2);
        return max(ans1, ans2);
    }
};