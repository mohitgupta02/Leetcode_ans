class Solution {
public:
    vector<vector<int>>ans;

    void recurPermute(vector<int>& nums,vector<int>& ds,int freq[]){
        if(ds.size()== nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i =0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                recurPermute(nums,ds,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>ds;
        int freq[nums.size()];
        for(int i =0;i<nums.size();i++) freq[i] =0;     
        recurPermute(nums,ds,freq);
        return ans; 
    }
};