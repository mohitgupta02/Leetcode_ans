class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int i, int j,string s, string p) {
        if (p.length() == j) {
            return s.length() == i;
        }

        bool first_char_match = false;
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if (i < s.length()&& (p[j] == s[i] || p[j] == '.')) {
            first_char_match = true;
        }

        if ((j+2 <= p.length()) && p[j+1] == '*') {
            bool not_take = solve(i,j+2,s, p);
            bool take = (first_char_match && solve(i+1,j,s, p));

            return dp[i][j]= not_take || take;
        }
        if (!s.empty() && !p.empty())
            return dp[i][j]=first_char_match && solve(i+1,j+1,s, p);
            return dp[i][j] = false;
    }
    bool isMatch(string s, string p) { 
        dp= vector<vector<int>>(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(0,0,s, p); 
    }
};