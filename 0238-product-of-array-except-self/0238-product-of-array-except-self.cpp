class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>preF(n);
        vector<int>suF(n);
        vector<int>res(n);

        preF[0] = 1;
        for(int i =1;i<n;i++){
            preF[i] = preF[i-1] * nums[i-1];
        }
        suF[n-1]=1;
        for(int i=n-2;i>=0;i--){
            suF[i] = suF[i+1] * nums[i+1];
        }
        for(int i =0;i<n;i++){
            res[i] = preF[i] * suF[i];
        }
        return res;
    }
};