class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return true;
        int maxi =0;
        for(int i=0;i<n;i++){
            if(i <= maxi){
                maxi = max(maxi, nums[i]+i);
            } else {
                return false;
            }
        }

        if(maxi >= n-1) return true;
        return false;
    }
};