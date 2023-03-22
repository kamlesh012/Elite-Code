class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> vp(n+1);
        for(auto i:roads){
            vp[i[0]].push_back({i[1],i[2]});
            vp[i[1]].push_back({i[0],i[2]});
        }
        queue<pair<int,int>> q;
        q.push({1,0});
        int mn=INT_MAX;
        vector<int> vis(n+1,0);
        vis[1]=1;
        while(q.size()){
            auto it=q.front();
            q.pop();
            int node=it.first;
            for(auto x:vp[node]){
                mn=min(mn,x.second);
                if(!vis[x.first])
                {
                    q.push({x.first,x.second});
                    vis[x.first]++;
                }
            }
        }
        return mn;
    }
};