class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);
        auto dfs=[&](int src,auto && dfs)->void{
            vis[src]++;
            for(auto i:rooms[src])if(!vis[i])dfs(i,dfs);
        };
        dfs(0,dfs);        
        return accumulate(vis.begin(),vis.end(),0)==n;
        
    }
};