class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<vector<int>> adjl(n);
        for(auto i:edges){
            adjl[i[0]].push_back(i[1]);
            adjl[i[1]].push_back(i[0]);
        }
        // vector<int> vis(n,0);
        int cnt=0ll;
        
        function<int (int src,int parent)> dfs=[&](int src,int parent){
            int sum=values[src];
            for(auto i:adjl[src]){
                // if(i!=prnt && vis[i]==0){
                if(i!=parent){
                    sum+=dfs(i,src);
                    sum%=k;
                }
            }
            if(sum%k==0)cnt++;
            return sum;
        };
        dfs(0,-1);
        return cnt;
    }
};