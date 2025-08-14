class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        int cnt = 1;
        string ans = "";

        for (int i = 1; i < n; i++) {
            if (num[i] == num[i-1]) {
                cnt++;
                if (cnt == 3) {
                    string current = string(3, num[i]);
                    if (ans.empty() || current > ans) {
                        ans = current;
                    }
                }
            } else {
                cnt = 1;
            }
        }
        return ans;
    }
};
