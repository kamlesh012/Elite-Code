class Solution {
public:
    int minCut(string s) {
        int n=s.length();
        vector<vector<int>> ispal(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                ispal[j][i]=s[i]==s[j]?j+1>=i || ispal[j+1][i-1]:false;
                // cout<<s.substr(j,i-j+1)<<endl;
                // cout<<ispal[j][i]<<endl;
            }
        };
        vector<int> dp(n+1,-1);
        function<int(int)> rec=[&](int i){
          if(i==n)return 0;
            if(dp[i]==-1){
                int ans=1e5;
                for(int j=i;j<n;j++){
                    if(ispal[i][j])ans=min(ans,rec(j+1)+1);
                }
                return dp[i]=ans;
            }
            return dp[i];
        };
        
        return rec(0)-1;
        
    }
};