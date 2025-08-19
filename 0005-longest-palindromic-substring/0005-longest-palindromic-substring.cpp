class Solution {
public:
    int t[1001][1001];
    bool check(string &s,int i, int j){
        if(i >= j) return 1;
        if(t[i][j] != -1){
            return t[i][j];
        }
        if(s[i] != s[j]){
            return 0;
        }
        return t[i][j] = check(s,i+1,j-1);
        
    } 
    string longestPalindrome(string s) {
        memset(t,-1,sizeof(t));

        int n = s.size();
        string ans = "";

        for(int i =0;i<n;i++){
            for(int j =i;j<n;j++){
                if(j-i+1 > ans.size() && check(s,i,j)){
                    ans = s.substr(i,j-i+1);
                }
            }
        }
        return ans;
    }
};