struct DSU {
    vector<int> size, parent;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(),parent.end(), 0);
    }
    void merge(int x, int y) {
        int px = find_parent(x);
        int py = find_parent(y);
        if (px == py)return;
        if (size[px] >= size[py]) {
            size[px] += size[py];
            parent[py] = px;
        }
        else {
            size[py] += size[px];
            parent[px] = py;
        }
    }
    int find_parent(int node) {
        if (parent[node] == node)return node;
        else {
            return find_parent(parent[node]);
        }
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU d(n);
        for(auto i:edges){
            d.merge(i[0],i[1]);
        }
        long long total=(n*1ll*(n-1))/2;
        set<int> parent;
        for(int i=0;i<n;i++){
            parent.insert(d.find_parent(i));
        }
        for(auto i:parent){
            long long curr=d.size[i];
            total-=(curr*(curr-1))/2ll;
        }
        return total;
        
    }
};