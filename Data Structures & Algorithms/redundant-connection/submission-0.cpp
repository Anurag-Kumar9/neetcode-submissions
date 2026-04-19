class DisjointSet {
public:
    vector<int> parent, size;
    int num;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        num = n;

        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int finduparent(int node){
        if(parent[node] == node) return parent[node];

        return parent[node] = finduparent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = finduparent(u);
        int ulp_v = finduparent(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            num--;
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
            num--;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        
        int x = ds.num;
        vector<int> ans;
        for(auto &e : edges){
            ds.unionBySize(e[0]-1, e[1]-1);
            if(ds.num != x-1) ans = e;
            else {
                x--;
            }
        }
        return ans;
    }
};