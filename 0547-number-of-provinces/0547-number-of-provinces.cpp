class Solution {
public:
    void dfs(vector<vector<int>>&adj, int start, vector<int>&vis){
        vis[start]=1;
        for(auto it:adj[start]){
            if(!vis[it]){
                dfs(adj,it,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>vis(n,0);
        int cnt =0;
        vector<vector<int>>adj(n);
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i =0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(adj, i,vis);
            }
        }
        return cnt;
    }
};