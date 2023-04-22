class Solution {
public:
    int rec(vector<vector<int>>& triangle,int i,int j,vector<vector<int>> &dp){
        if(j==triangle.size())return 0;
        if(i>=triangle[j].size())return INT_MAX;
        
        // cout<<j<<" "<<i<<" "<<triangle[j][i]<<endl;
        if(dp[j][i]==-1){
            dp[j][i]=triangle[j][i]+min(rec(triangle,i,j+1,dp),rec(triangle,i+1,j+1,dp));
        }
        return dp[j][i];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        // Memoized
        // int n=triangle.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return rec(triangle,0,0,dp);
        
        //Tabulated
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;--i){
            for(int j=0;j<=i;j++){
                if(i==n-1){
                    dp[i][j]=triangle[i][j];
                }
                else{
                    
                    if(j+1<=(i+1))
                    dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
                    
                    else dp[i][j]=triangle[i][j]+dp[i+1][j];
                }
            }
        }
        return dp[0][0];
    }
};