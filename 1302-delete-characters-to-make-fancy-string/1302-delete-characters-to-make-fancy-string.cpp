class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string m;
        if(s.size() <= 2) return s;
        for(int i=0;i<n;i++){
            if(s[i] == s[i+1]  && s[i] == s[i+2]){
                continue;
            }else{
                m.push_back(s[i]);
            }
        }
        return m;
    }
};