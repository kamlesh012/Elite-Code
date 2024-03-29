class Solution {
public:
    int minCut(string s) {
        //Classical DP Problem to pre-calculate whether a substring is palindromic or not
        //for all substring in O(n^2).
        int n=s.length();
        vector<vector<int>> ispal(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                ispal[j][i]=s[i]==s[j]?j+1>=i || ispal[j+1][i-1]:false;
            }
        };
        
      //  //Recursive 1D DP Solution.
       // //Instead of using start & end as two states for each substring,
       // //I considered current end as next start -1.(taking advantage of rightboundary)
      //  //By doing this clever technique one state has been reduced.
        
// //dp[i] stores the minimum number of palindromic substrings that exist from index i to n
        // vector<int> dp(n+1,-1);
        // function<int(int)> rec=[&](int i){
        //   if(i==n)return 0;
        //     if(dp[i]==-1){
        //         int ans=1e5;
        //         for(int j=i;j<n;j++){
        //             if(ispal[i][j])ans=min(ans,rec(j+1)+1);
        //         }
        //         return dp[i]=ans;
        //     }
        //     return dp[i];
        // };
        // //returning ans-1 beause ans store min no. of palindromic substrings. 
        // //but we need splits. so splits will be no. of strings -1.
        
        // return rec(0)-1;
        
        //That same recursive thing can be tabulated.
        vector<int> dp(n+1,1e5);
        dp[n]=0;//basecase
        for(int i=n-1;i>=0;--i){
            for(int j=i;j<n;j++){
                if(ispal[i][j])dp[i]=min(dp[i],dp[j+1]+1);
            }
        }
        return dp[0]-1;
        
        //2d-DP Failing in making states.
        //here in this case I want to not consider next start for current end.
        //will do it later.
//         vector<vector<int>> dp(n+1,vector<int>(n+1,1e5));
        
//         for(int i=n;i>=0;--i){
//             int ans=1e5;
//             for(int j=i;j<n;j++){
//                 if(i==n)dp[j][i]=0;
//                 else if(ispal[j][i])
//                 dp[j][i]=min(dp[j][i],dp[j+1][i]+1);
//             }
//         }
//         return dp[0][0];
        
    }
};