class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n=a.length(),m=b.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        function<int(int i,int j)> rec=[&](int i,int j){
          if(i>=n || j>=m)  return 0;
            if(dp[i][j]!=-1)return dp[i][j];
            int ans=0;
            if(a[i]==b[j]){
                ans=1+rec(i+1,j+1);
            }
            else ans=max(rec(i+1,j),rec(i,j+1));
            return dp[i][j]=ans;
        };
        return rec(0,0);
    }
};