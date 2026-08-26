class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(int i = 0; i < prerequisites.size(); i++){
            int course = prerequisites[i][0];
            int pre = prerequisites[i][1];
            indegree[course]++;
            adj[pre].push_back(course);
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){
            int c = q.front();
            q.pop();
            for(auto it : adj[c]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
        }
        if(ans.size() == numCourses) return ans;
        else return {};
    }
};
