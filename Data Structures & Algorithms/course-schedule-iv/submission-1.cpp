class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));

        for(auto it : prerequisites){
            int course = it[0];
            int pre = it[1];
            reachable[pre][course] = true;
        }

        for(int k = 0; k < numCourses; k++){
            for(int j = 0; j < numCourses; j++){
                for(int i = 0; i < numCourses; i++){
                    if(reachable[i][k] && reachable[k][j]){
                        reachable[i][j] = true;
                    }
                }
            }
        }

        vector<bool> ans;
        for(auto query : queries){
            int course = query[0];
            int pre = query[1];

            ans.push_back(reachable[pre][course]);
        }
        return ans;
    }
};