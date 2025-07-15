class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n= nums.size();
        int first = INT_MAX;
        int second = INT_MAX;

        for(auto it: nums){
            if(it <= first){
                first = it;
            } else if( it <= second){
                second = it;
            } else{
                return true;
            }
        }
        return false;
    }
};