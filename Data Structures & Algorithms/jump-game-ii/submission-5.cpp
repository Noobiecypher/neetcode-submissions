class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int reach = 0;
        queue<int> q;
        vector<int> visited(n,0);
        int count = 0;
        visited[0] = 1;
        q.push(0);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int j = q.front();
                q.pop();
                reach = min(n-1, nums[j] + j);
                for(int i = j + 1; i <= reach; i++){
                    if(visited[i]) continue;
                    if(i == n - 1) return count + 1;
                    visited[i] = 1;
                    q.push(i);
                }
            }
            count++;
        }
        return count;
    }
};
