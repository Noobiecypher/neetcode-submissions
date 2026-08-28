class DisjointSet{
    vector<int> parent;
    vector<int> size;
    public: 
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int fup(int node){
        if(parent[node] == node) return node;
        return parent[node] = fup(parent[node]);
    }

    void ubs(int u, int v){
        int ulp = fup(u);
        int vlp = fup(v);
        if(ulp == vlp) return;
        if(size[ulp] > size[vlp]){
            size[ulp]+=size[vlp];
            parent[vlp] = ulp;
        }

        else{
            size[vlp]+=size[ulp];
            parent[ulp] = vlp;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            if(ds.fup(u) == ds.fup(v)){
                return {u,v};
            }

            ds.ubs(u,v);
        }
        return {};
    }
};
