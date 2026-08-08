class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        queue<int> q;
        vector<int> vis(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                q.push(i);
                count++;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    vis[node] = 1;
                    for(auto it : adj[node]){
                        if(!vis[it]){
                            q.push(it);
                        }
                    }
                }
            }
        }
        return count;
    }
};
