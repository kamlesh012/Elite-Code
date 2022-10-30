class Solution {
public:
    int rec(vector<vector<vector<int>>> & dp,vector<vector<int>> & grid,int i,int a,int b){
        int n=grid.size(),m=grid[0].size();
        if(i>=n || a<0 || a>=m || b<0 || b>=m)return 0;
        if(dp[i][a][b]==-1){
            
            if(a==b){                                                                           
                int ans=0;
                // ans=max(ans,rec(dp,grid,i+1,a-1,b-1)+grid[i][a]);
                ans=max(ans,rec(dp,grid,i+1,a-1,b)+grid[i][a]);
                ans=max(ans,rec(dp,grid,i+1,a-1,b+1)+grid[i][a]);

                ans=max(ans,rec(dp,grid,i+1,a,b-1)+grid[i][a]);
                // ans=max(ans,rec(dp,grid,i+1,a,b)+grid[i][a]);
                ans=max(ans,rec(dp,grid,i+1,a,b+1)+grid[i][a]);

                ans=max(ans,rec(dp,grid,i+1,a+1,b-1)+grid[i][a]);
                ans=max(ans,rec(dp,grid,i+1,a+1,b)+grid[i][a]);
                // ans=max(ans,rec(dp,grid,i+1,a+1,b+1)+grid[i][a]);
                dp[i][a][b]=ans;
            }
            
            else{
            int ans=0;
            ans=max(ans,rec(dp,grid,i+1,a-1,b-1)+grid[i][a]+grid[i][b]);
            ans=max(ans,rec(dp,grid,i+1,a-1,b)+grid[i][a]+grid[i][b]);
            ans=max(ans,rec(dp,grid,i+1,a-1,b+1)+grid[i][a]+grid[i][b]);

            ans=max(ans,rec(dp,grid,i+1,a,b-1)+grid[i][a]+grid[i][b]);
            ans=max(ans,rec(dp,grid,i+1,a,b)+grid[i][a]+grid[i][b]);
            ans=max(ans,rec(dp,grid,i+1,a,b+1)+grid[i][a]+grid[i][b]);

            ans=max(ans,rec(dp,grid,i+1,a+1,b-1)+grid[i][a]+grid[i][b]);
            ans=max(ans,rec(dp,grid,i+1,a+1,b)+grid[i][a]+grid[i][b]);
            ans=max(ans,rec(dp,grid,i+1,a+1,b+1)+grid[i][a]+grid[i][b]);
            dp[i][a][b]=ans;
            }
        }
            return dp[i][a][b];   
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size()+1,vector<vector<int>> (grid[0].size()+1,vector<int>(grid[0].size()+1,-1)));
        
        // vector<vector<vector<int>>> dp(700+1,vector<vector<int>> (200+1,vector<int>(200+1,-1)));
        
        return rec(dp,grid,0,0,grid[0].size()-1);
    }
};