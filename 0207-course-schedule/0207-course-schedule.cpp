class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto p : prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int comp = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            comp++;
            for(auto e : adj[course]){
                indegree[e]--;
                if(indegree[e]==0){
                    q.push(e);
                }
            }
        }
        return numCourses==comp;
    }
};