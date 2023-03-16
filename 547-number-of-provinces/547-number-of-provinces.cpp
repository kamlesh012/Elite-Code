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
    int findCircleNum(vector<vector<int>>& graph) {
        int n=graph.size();
        DSU d(n+1);
        set<int> components;
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[0].size();j++){
                if(graph[i][j]){
                    d.join(i+1,j+1);
                }
            }
        }
      for(int i=1;i<=n;i++){
          components.insert(d.find_parent(i));
      }
    return components.size();
    }
};