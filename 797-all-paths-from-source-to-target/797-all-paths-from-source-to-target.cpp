class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int src,vector<vector<int>> &graph,vector<int> &visited,vector<int>&path){
        
        // visited[src]=1;
        path.push_back(src);
        
        if(src==graph.size()-1)ans.push_back(path);
        
            for(auto i:graph[src]){
                // if(i==graph.size()-1 || !visited[i])
                dfs(i,graph,visited,path);
            }
        
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> visited(n,0);
        vector<int> path;
        dfs(0,graph,visited,path);
        return ans;
    }
};