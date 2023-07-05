class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int diag=0,top=0,left=0;
                if(i-1>=0 && j-1>=0)diag=dp[i-1][j-1];
                if(i-1>=0)top=dp[i-1][j];
                if(j-1>=0)left=dp[i][j-1];
                if(mat[i][j]=='0')dp[i][j]=0;
                else{
                    dp[i][j]=min({diag,top,left})+1;
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};