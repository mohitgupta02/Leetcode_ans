class Solution {
public:
    string minWindow(string s, string t) {
        int m = t.size();
        int n = s.size();

        int l =0;
        int r =0;
        vector<int>hash(256,0);
        int minLen =INT_MAX;
        int sIndex =-1;
        int cnt =0;
        for(int i =0;i<m;i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0) cnt++;
            hash[s[r]]--;
            while(cnt == m){
                if((r-l+1) < minLen){
                    minLen = r-l+1;
                    sIndex=l;
                }
                    hash[s[l]]++;
                    if(hash[s[l]]>0) cnt = cnt -1;
                    l++;
                
            }
            r = r+1;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};