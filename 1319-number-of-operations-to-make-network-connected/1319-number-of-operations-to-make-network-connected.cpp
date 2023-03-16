struct DSU {
    vector<int> size, parent;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(),parent.end(),0);
    }
    void join(int x, int y) {
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
        return parent[node]=find_parent(parent[node]);
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU d(n);
        int cables=connections.size();
        for(auto i:connections){
            d.join(i[0],i[1]);
        }
        set<int> networks;
        for(int i=0;i<n;i++){
            networks.insert(d.find_parent(i));
        }
        int m=networks.size();
        if(cables<(n-1))return -1;
        else return m-1;
    }
};