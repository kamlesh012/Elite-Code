class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int src,vector<vector<int>> &graph,vector<int>&path){
        path.push_back(src);
        
        if(src==graph.size()-1)ans.push_back(path);
        
            for(auto i:graph[src]){
                dfs(i,graph,path);
            }
        
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> path;
        dfs(0,graph,path);
        return ans;
    }
};