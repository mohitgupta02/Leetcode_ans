class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mpp;
        int l=0;
        int r=0;
        int maxLen =0;
        while(r<fruits.size()){
            mpp[fruits[r]]++;

            if(mpp.size() > 2){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]] ==0){
                        mpp.erase(fruits[l]);
                    }
                    l++;
            }
            maxLen =max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};