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
        int n=triangle.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return rec(triangle,0,0,dp);
    }
};