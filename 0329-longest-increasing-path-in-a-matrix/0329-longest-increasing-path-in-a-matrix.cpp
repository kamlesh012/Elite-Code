class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //Brute Force DFS+Cache.
        
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        function<int(int,int)> dfs=[&](int i,int j){
            int res=0;
            for(int x=-1;x<=1;x++){
                for(int y=-1;y<=1;y++){
                    if((!x && y) || (x && !y)){
                        if(i+x>=0 && j+y>=0 && i+x<n && j+y<m && matrix[i+x][j+y]>matrix[i][j]){
                            if(vis[i+x][j+y])res=max(res,vis[i+x][j+y]);
                            else res=max(res,dfs(i+x,j+y));
                        }
                            
                    }
                }
            }
            vis[i][j]=res+1;
            return res+1;
        };
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    ans=max(ans, dfs(i,j));
                }
            }
        }
        return ans;
    }
};