class Solution {
public:
    int maxNonDecreasingLength(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<vector<int>> dp(n+1,vector<int>(2,1));
        int ans=1;
        for(int i=1;i<n;i++){
            int prev1=a[i-1],prev2=b[i-1];
            // prev1=a[i-1];
            // prev2=b[i-1];
            
            if(a[i]>=prev1)dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
            if(a[i]>=prev2)dp[i][0]=max(dp[i][0],dp[i-1][1]+1);
            
            if(b[i]>=prev1)dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
            if(b[i]>=prev2)dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
            
            ans=max(ans,dp[i][0]);
            ans=max(ans,dp[i][1]);
        }
        return ans;
    }
};