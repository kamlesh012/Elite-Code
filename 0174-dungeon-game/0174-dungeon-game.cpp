class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int dp[201][201];
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=0;--j){
                if(i==n-1 && j==m-1){
                    //Base Case
                    dp[i][j]=(a[i][j]>=0)?1:-a[i][j]+1;
                }
                else{
                    int bottom=1e9,right=1e9;
                    if(i+1<n)bottom=dp[i+1][j];
                    if(j+1<m)right=dp[i][j+1];
                    
                    int ans=min(bottom,right)-a[i][j];
                    if(ans<=0)ans=1;
                    dp[i][j]=ans;
                }
            }
        }
        return dp[0][0];
    }
};