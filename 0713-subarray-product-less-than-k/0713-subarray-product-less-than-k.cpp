class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt =0;
        int i =0;
        int j =0;
        int prod =1;
        while(j<n){
            prod *= nums[j];
        
            while (prod >= k && i <= j) {
                prod /= nums[i];
                i++;
            }
            cnt += (j-i+1);
            j++;

        }
        return cnt;
    }
};