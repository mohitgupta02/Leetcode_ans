class Solution {
public:

    int solve(int i , vector<int>& nums,vector<int>&dp,int n ){
        if(i > n) return 0;
        if(dp[i] != -1) return dp[i];
        int steal = nums[i] + solve(i+2,nums,dp,n);
        int skip = solve(i+1,nums,dp,n);

        return dp[i] = max(steal,skip);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n+1,-1);
        int case1 = solve(0,nums,dp,n-2);
        vector<int>dp1(n+1,-1);
        int case2 = solve(1,nums,dp1,n-1);
        return max(case1,case2);
    }
};