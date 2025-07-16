class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n  = nums.size();
        int evennum =0;
        int oddnum=0;
        int paritycnt =1;
        for(int i=0;i<n;i++){
            if(nums[i]%2== 0){
                evennum++;
            }
            else  oddnum++;
        }
        int parity = nums[0] %2;
        for(int i=1;i<n;i++){
            int curr = nums[i] %2;
            if(curr != parity){
                paritycnt++;
                parity = curr;
            }
        }
        return max({evennum,oddnum,paritycnt});

    }
};