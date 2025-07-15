class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n ==1) return 0;
        vector<int>cum(n,0);
        int cnt =0;
        for(int i =0;i<n;i++){
             cnt += nums[i];
             cum[i] = cnt; 
        }
        int tsum =0;
        for(int i =0;i<n;i++){
            tsum += nums[i];
        }
        if (tsum - nums[0] == 0) return 0;        
        for(int i=1;i<n;i++){
            if(cum[i-1] == (tsum-nums[i]-cum[i-1])){
                return i;
            }
        }

        return -1;
    }
};