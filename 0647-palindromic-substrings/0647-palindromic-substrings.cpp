class Solution {
public:
    int countSubstrings(string s) {
     int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                dp[j][i]=((s[i]==s[j])?(j+1>=i || dp[j+1][i-1]):false);
                ans+=dp[j][i];
            }
        }
        return ans;
        
    }
};