#define mod 1000000007
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(target+1,0)));
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(target+1,vector<int>(k+1,0)));
        // vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        
//         for(int i=0;i<=n;i++){
//             for(int t=0;t<=target;t++){
//                 for(int j=0;j<=k;j++){
// //                     This fucking Base case was the culprit.
//                     if(t==0 && i==0)dp[i][t]=1;
//                     else if(t==0 || i==0 || j==0)continue;
//                         //same as dp[i][t]=0;
//                     else {
//                             if(j<=t)
//                                 dp[i][t]=((dp[i][t]%mod)+(dp[i-1][t-j]%mod))%mod;
//                         }
//                 }
//             }
//         }
//         return dp[n][target];
        
        //Failed Approaches
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        function<int(int,int)> rec=[&](int i,int t){
            if(i==n && t==0)return 1;
            else if(i==n || t==0)return 0;
            
            //THis f*ing base case was wrong.
            // if(i==n){
                // if(t==0)
                // return 1;
                // else return 0;
            // }
            // if(t==0)return 1;
            
            int &ans=dp[i][t];
            if(ans!=-1)return ans;
            int curr=0;
            for(int j=1;j<=k;j++){
                if(j<=t)curr=((curr%mod)+(rec(i+1,t-j)%mod))%mod;
            }
            return ans=curr;
        };
        
        return rec(0,target);
        
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=k;j++){
        //         for(int t=0;t<=target;t++){           
        //             if(t==0)dp[i][j][t]=1;
        //             else if(j==0 || i==0)dp[i][j][t]=0;
        //             else{
        //                 if(t-k>=0)dp[i][j][t]+=dp[i-1][j][t-j];
        //             }
        //         }
        //     }
        // }
        // return dp[n-1][k-1][target-1];
            
    }
};