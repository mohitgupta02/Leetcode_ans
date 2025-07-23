class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long total =0;
        long long largest =0;
        long long smallest=0;


        for(int i =0;i<n;i++){
            largest = nums[i], smallest= nums[i];
            for(int j=i+1;j<n;j++){
                largest = max(largest, (long long)nums[j]);
                smallest = min(smallest, (long long)nums[j]);

                total = total + (largest -smallest);
            }
        }
        return total;
    }
};