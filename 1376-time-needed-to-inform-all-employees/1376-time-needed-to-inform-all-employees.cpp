class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adjl(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
            {
                adjl[i].push_back(manager[i]);
                adjl[manager[i]].push_back(i);
            }
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<i<< " "<<endl;
        //     for(auto j:adjl[i])cout<<j<< " ";
        //     cout<<endl;
        // }
        
        vector<int> vis(n,0);
        function<int(int)> dfs=[&](int src){
            vis[src]++;
            int time=0;
            for(auto i:adjl[src]){
                if(!vis[i]){
                    // int call=dfs[i];
                    time=max(time,dfs(i));
                }
            }
            return time+informTime[src];
        };
        return dfs(headID);
    }
};