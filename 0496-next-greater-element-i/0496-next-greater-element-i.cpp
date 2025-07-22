class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n = nums1.size();
        int m = nums2.size();
        int flag=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(nums2[j] == nums1[i]){
                    flag =0;
                    for(int k =j+1; k<m;k++){
                        if(nums2[k] > nums1[i]){
                            ans.push_back(nums2[k]);
                            flag=1;
                            break;
                        }
                    }
                    if(flag ==0) ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};