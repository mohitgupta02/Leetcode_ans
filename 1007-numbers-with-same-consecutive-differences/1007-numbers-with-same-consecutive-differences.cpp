class Solution {
public:
    void dfs(int n , int num,int k , vector<int>&ans){
        if(n == 0){
            ans.push_back(num);
            return;
        }

        int tail = num % 10;

        if(tail + k < 10){
            dfs(n-1,num *10 + tail + k,k,ans);
        }
        if(k != 0 && tail - k >=0){
            dfs(n-1,num * 10 + tail-k,k,ans);
        }
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;

        if(n==1) ans.push_back(0);

        for(int i=1;i<10;i++){
            dfs(n-1,i,k,ans);
        }

        return ans;
    }
};