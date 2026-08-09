class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }

        vector<int> price(n, 1e9);
        queue<pair<int, pair<int, int>>> q;
        price[src] = 0;
        q.push({0, {src, 0}});
        while (!q.empty()) {
            vector<int> temp;
            int size = q.size();

            while (size--) {
                auto curr = q.front();
                q.pop();
                int stops = curr.first;
                int node = curr.second.first;
                int wt = curr.second.second;

                if (stops > k) continue;
                for (auto it : adj[node]) {
                    int v = it.first;
                    int edgewt = it.second;

                    if (edgewt + wt < price[v]) {
                        price[v] = edgewt + wt;
                        q.push({stops + 1, {v, price[v]}});
                    }
                }
                price = temp;
            }
        }
        if (price[dst] == 1e9) return -1;
        return price[dst];
    }
};
