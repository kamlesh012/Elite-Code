class Solution {
public:
    string longestPalindrome(string s)
    {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,false));
        
        int l=0,start=0;
        string ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                dp[j][i]=(s[j]==s[i]?(j+1>=i || dp[j+1][i-1]):false);
                if(dp[j][i] && i-j>l){
                    l=i-j;
                    start=j;
                }
            }
        }
        ans=s.substr(start,l+1);
        return ans;
    }
};