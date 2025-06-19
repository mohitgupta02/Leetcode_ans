class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0;
        int r =0;
        int maxF =0;
        int maxLen =0;
        // unordered_map<int,int>mpp;
        vector<int>mpp(26,0);
        while(r<n){
            mpp[s[r]-'A']++;
            maxF = max(maxF,mpp[s[r]-'A']);
            if( (r-l+1)-maxF > k){
                mpp[s[l]-'A']--;       
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};