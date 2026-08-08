class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty()){
            auto [tm, node] = pq.top();
            pq.pop();
            for(auto [v,t] : adj[node]){
                if(tm + t < dist[v]){
                    dist[v] = tm + t;
                    pq.push({dist[v],v});
                }
            }
        }
        int maxTime = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9){
                return -1;
            }
            maxTime = max(dist[i],maxTime);
        }
        return maxTime;
    }
};
