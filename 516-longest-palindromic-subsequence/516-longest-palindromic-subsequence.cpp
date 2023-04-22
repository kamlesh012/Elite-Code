class Solution {
public:
    
    int lcs(string &a,string &b,int i,int j,vector<vector<int>>& dp){
        if(i==a.length() || j==b.length())return 0;
        if(dp[i][j]==-1){
            if(a[i]==b[j]){
                return dp[i][j]=lcs(a,b,i+1,j+1,dp)+1;
            }
            else{
                return dp[i][j]=max(lcs(a,b,i+1,j,dp),lcs(a,b,i,j+1,dp));
            }
        }
        return dp[i][j];
    }
    int withoutlcs(string &s,int i,int j,vector<vector<int>>& dp){
        if(i==j)return 1;
        if(i>j)return 0;
        if(dp[i][j]==-1){
            if(s[i]==s[j])return dp[i][j]=2+withoutlcs(s,i+1,j-1,dp);
            else {
                return dp[i][j]=max(withoutlcs(s,i+1,j,dp),withoutlcs(s,i,j-1,dp));
            }
        }
        return dp[i][j];
    }
        
    int longestPalindromeSubseq(string s) {
        //USING LCS.
        //  LCS(string,reverse(string))==LPS(string)
        
        // string ans=s;
        // reverse(ans.begin(),ans.end());
        // int n=s.length();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return lcs(s,ans,0,0,dp);
        
        //without lcs
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return withoutlcs(s,0,n-1,dp);
    }
};