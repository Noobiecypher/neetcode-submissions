class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1)return false;
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);
        queue<pair<int,int>> q;
        q.push({0,-1});
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(it == parent) continue;
                if(vis[it] == 1) return false;
                vis[it] = 1;
                q.push({it, node});
            }
        }
        for(int i = 0; i < n; i++){
            if(vis[i] == 0) return false;
        }
        return true;
    }
};
