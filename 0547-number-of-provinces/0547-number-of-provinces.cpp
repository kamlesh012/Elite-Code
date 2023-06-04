class Solution {
public:
    int findCircleNum(vector<vector<int>>& iscon) {
        int n=iscon.size();
     vector<vector<int>> adjl(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    if(iscon[i][j]){
                        adjl[i+1].push_back(j+1);
                    }
            }
        }
        
        vector<int> vis(n+1,0);
        auto bfs=[&](int src){
            queue<int> q;
            vis[src]++;
            q.push(src);
            
            while(q.size()){
                auto node=q.front();
                q.pop();
                for(auto j:adjl[node]){
                    if(!vis[j]){
                        vis[j]++;
                        q.push(j);
                    }
                }
            }
        };
        
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(!vis[i])bfs(i),cnt++;
        
        return cnt;
    }
};