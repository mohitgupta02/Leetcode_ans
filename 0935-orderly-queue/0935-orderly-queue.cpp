class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        } else {
            string res = s;
            int n = s.size();
            for (int i = 1; i < n; i++) {
                string rotated = s.substr(i) + s.substr(0, i);
                if (rotated < res) {
                    res = rotated;
                }
            }
            return res;
        }
    }
};
