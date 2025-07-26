class Solution {
public:
    int kadane(vector<int>&nums, int n){
        int sum =nums[0];
        int maxi =nums[0];
        for(int i =1;i<n;i++){
            sum = max(sum+nums[i],nums[i]);
            maxi = max(maxi,sum);
        }
        return maxi;
    }

    int solve(vector<int>&nums,int n){
        int sum =nums[0];
        int mini= nums[0];
        for(int i =1;i<n;i++){
            sum = min(sum + nums[i],nums[i]);
            mini = min(mini,sum);
        }
        return mini;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int tSum =0;

        for(int i =0;i<n;i++){
            tSum += nums[i];
        }

        int s2 = solve(nums,n);
        int ans1 = kadane(nums,n);
        if(ans1 < 0) return ans1;   
        int ans2 = tSum -s2;
        return max(ans1,ans2);
    }
};