class Solution {
public:
    bool dfs(vector<vector<int>> &adjl,vector<int> &visited,int src,int dest){
        
        visited[src]=1;
        if(src==dest)return true;
        bool ok=false;
        
        for(auto i:adjl[src]){
            if(!visited[i]){
                ok=ok|dfs(adjl,visited,i,dest);
            }
            
        }
        
        return ok;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<vector<int>> adjl(n);
        for(auto i:edges){
            adjl[i[0]].push_back(i[1]);
            adjl[i[1]].push_back(i[0]);
        }
        vector<int> visited(n,0);
        return dfs(adjl,visited,source,destination);
    }
};