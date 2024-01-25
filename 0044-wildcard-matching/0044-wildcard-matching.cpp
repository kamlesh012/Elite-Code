class Solution {
public:
    // int dp[2001][2001]={-1};
    bool isMatch(string s, string p,int i=0,int j=0) {
        int n=s.length(),m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        function<int(int i,int j)> mem=[&](int i,int j){
            if(i==n){
                if(j==m)return 1;
                if(p[j]!='*')return 0;
                else {
                    if(dp[i][j]!=-1)return dp[i][j];
                    else return dp[i][j]=mem(i,j+1);
                }
            }
            if(j==m)return 0;
            if(dp[i][j]!=-1)return dp[i][j];

            if(i<n && j<m && s[i]==p[j]){
                return dp[i][j]=mem(i+1,j+1);
            }
            else{
                bool pick=false,skip=false;
                if(p[j]=='*'){
                    pick=mem(i+1,j);
                    skip=mem(i,j+1);
                    return dp[i][j]= pick || skip;
                }
                else if(p[j]=='?')return dp[i][j]=mem(i+1,j+1);
                else return dp[i][j]=0;
            }    
        };
        return mem(0,0);
        
    }
};