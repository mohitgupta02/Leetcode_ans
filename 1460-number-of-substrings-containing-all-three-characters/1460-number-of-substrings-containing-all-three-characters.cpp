class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<int,int>mpp;
        int n = s.size();
        int l=0;
        int r =0;
        int cnt =0;

        while(r<n){
            mpp[s[r]-'a']++;
            while(mpp.size() == 3){
                cnt = cnt + (n-r);
                mpp[s[l]-'a']--;
                if (mpp[s[l] - 'a'] == 0) {
                    mpp.erase(s[l] - 'a');
                }
                l++;   
            }
            r++;
        }
        return cnt;
    }
};