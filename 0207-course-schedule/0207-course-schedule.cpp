class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<int>adj[numCourses];
        // for(auto it:prerequisites){
        //     adj[it.first].push_back(it.second);
        // }

                vector<int>ans;
        queue<int>q;
        vector<int>indegree(numCourses,0);
        
        
        
        vector<vector<int>>adj(numCourses);
        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
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
        if(ans.size() == numCourses) return true;
        return false;
    }
};