class Solution {
public:
    void reverseString(string &s, int start, int end) {
        
        // Reversing the string character by character
        while(start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++, end--;
        }
        return;
    }
    string reverseWords(string s) {
        int n = s.length();
        int start =0;
        int end =0;
        int i =0;
        int j=0;
        reverseString(s,0,n-1);
        while(j<=n){
            while(j <n && s[j] == ' ') j++;
            
            if(j>=n) break;
            start =i;

            while(j<n && s[j] != ' '){
                s[i] = s[j];
                j++;
                i++;
            }
            end = i-1;
            reverseString(s,start,end);

            if(i<n){
            s[i++] = ' ';
            
            // if (i > 0 && s[i - 1] == ' ') i--;
            }
        }
        string ans = s.substr(0, end +1);
        return ans;
    }
};