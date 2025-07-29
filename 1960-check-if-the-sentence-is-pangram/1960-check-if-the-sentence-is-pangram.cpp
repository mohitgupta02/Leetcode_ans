class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>ans(26,0);
        int cnt =0;

        for(int i =0;i<sentence.size();i++){
            int ind = sentence[i] -'a';
            if(ans[ind]==0){
                ans[ind]++;
                cnt++;
            }
        }
        

        return cnt ==26;
    }

};