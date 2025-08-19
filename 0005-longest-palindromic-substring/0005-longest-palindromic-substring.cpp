class Solution {
public:
    void check(string &s, int t, int u, string &ans){
        string temp = "";
        int i =t;
        int j =u;
        while(i <= j){
            if(s[i]== s[j]){
                i++;
                j--;
            }else{
                return;
            }
        }
        temp = s.substr(t,u-t+1);
        if(temp.size() > ans.size()){
            ans = temp;
        }
    } 
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";

        for(int i =0;i<n;i++){
            for(int j =i;j<n;j++){
                if(j-i+1 > ans.size()){
                    check(s,i,j,ans);
                }
            }
        }
        return ans;
    }
};