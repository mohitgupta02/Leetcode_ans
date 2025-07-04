class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        queue<int>q;
        vector<int>indegree(numCourses,0);
        
        
        
        vector<vector<int>>adj(numCourses);
        for (auto& edge : prerequisites) {
            int u = edge[1];
            int v = edge[0];
            adj[u].push_back(v);
        }
        
        
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i =0;i<numCourses;i++){
            if(indegree[i] ==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node =q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
            
        }
        if(ans.size() == numCourses) return ans;
        return {};
    }
};