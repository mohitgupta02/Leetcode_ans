class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>result(n+1,1e9);
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        result[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for(auto &it:adj[node]){
                int adjNode=it.first;
                int ewt = it.second;

                if(dist + ewt < result[adjNode]){
                    result[adjNode] = dist+ewt;
                    pq.push({dist+ewt,adjNode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            ans = max(ans,result[i]);
        }
        return ans == 1e9 ?-1:ans;
    }
};