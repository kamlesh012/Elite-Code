class Solution {
public:
    void dfs(vector<vector<int>>& adjm,vector<int>& visited,int source){
        visited[source]++;
        for(int i=0;i<adjm.size();i++){
            if(adjm[source][i] && !visited[i]){
                dfs(adjm,visited,i);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        //DFS in a Adjacency Matrix.
        int n=isConnected.size();
        vector<int> visited(n+1,0);
        int component=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected,visited,i);
                component++;
            }
        }
        return component;
    }
};