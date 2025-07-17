class Solution {
public:
    // bool solve(vector<int>&arr, int sum , int ind){
    //     if(sum == 0) return true;
    //     if(ind >= arr.size()) return false;
    //     if(dp[ind][sum] != -1){
    //         return dp[ind][sum];
    //     }
    //     if(arr[ind] <= sum){
    //         return dp[ind][sum] = solve(arr,sum - arr[ind],ind+1) || solve(arr,sum,ind+1);
    //     }else{
    //         return dp[ind][sum] =solve(arr,sum,ind+1);
    //     }
    // }
    bool canPartition(vector<int>& nums) {
        int dp[201][10001];
        int sum = 0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            sum += nums[i];
        }
        if(sum %2 == 1) return false;
        sum = sum/2;
        for(int i =0;i<n+1;i++){
                dp[i][0]=true;
        }
        for(int i =1;i<n+1;i++){
            for(int j =1;j<sum+1;j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];

    }
};