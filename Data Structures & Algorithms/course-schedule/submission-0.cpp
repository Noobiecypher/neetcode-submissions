class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int inner = prerequisites[i][1];
            indegree[course]++;
            adj[inner].push_back(course);
        }
        int num = 0;
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                num++;
            }
        }
        
        while(!q.empty()){
            int course = q.front();
            q.pop();
            for(auto it : adj[course]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                    num++;
                }
            }
        }
        return num == numCourses;
    }
};
