class Solution {
public:
    int mod=1e9+7;
    
    int rec(int i,int j,int sum,int k,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        
        if(i>=grid.size() || j>=grid[0].size())return 0;
        
        sum=(sum%k+grid[i][j]%k)%k;
        
        if(i==grid.size()-1 && j==grid[0].size()-1 && sum==0)return 1;
        if(i==grid.size()-1 && j==grid[0].size()-1 && sum!=0)return 0;
        
        if(dp[i][j][sum%k]==-1){
        int one=rec(i+1,j,sum,k,grid,dp);
        int two=rec(i,j+1,sum,k,grid,dp);
            dp[i][j][sum%k]=(one%mod+two%mod)%mod;
        }
        return dp[i][j][sum%k];
        
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return rec(0,0,0,k,grid,dp);
    }
};