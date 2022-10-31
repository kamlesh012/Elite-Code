class Solution {
public:
    bool ok=false;
int rec(vector<vector<vector<vector<int>>>> & dp,vector<vector<int>> & grid,int i,int j,int a,int b){
        int n=grid.size();
        if((i==n-1 && j==n-1) && (a==n-1 && b==n-1)){
            if(grid[i][j]==-1)return 0;
            else {
                ok=true;
                return grid[i][j];
            }
        }
    
        if(i>=n || j>=n || a>=n || b>=n || grid[i][j]==-1 || grid[a][b]==-1)return INT_MIN;
    
        if(dp[i][j][a][b]==-1){
            
            int cherry=0;
            if(i==a && j==b)cherry=grid[i][j];
            else cherry=grid[i][j]+grid[a][b];
            
            int ans=INT_MIN;
            
            ans=max(ans,rec(dp,grid,i+1,j,a+1,b));
            ans=max(ans,rec(dp,grid,i+1,j,a,b+1));
            
            ans=max(ans,rec(dp,grid,i,j+1,a+1,b));
            ans=max(ans,rec(dp,grid,i,j+1,a,b+1));
            
            cherry+=ans;
            
            if(!ok)cherry=0;
            dp[i][j][a][b]=cherry;
        }
            return dp[i][j][a][b];   
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int  n=grid.size();
        vector<vector<vector<vector<int>>>> dp(n+1,vector<vector<vector<int>>> (n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1))));
        
        return rec(dp,grid,0,0,0,0);
    }
};
