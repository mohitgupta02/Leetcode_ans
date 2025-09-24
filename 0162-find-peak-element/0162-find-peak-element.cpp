class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        // Get iterator to max element
        auto it = max_element(nums.begin(), nums.end());
        
        // Convert iterator to index
        return distance(nums.begin(), it);
    }
};
