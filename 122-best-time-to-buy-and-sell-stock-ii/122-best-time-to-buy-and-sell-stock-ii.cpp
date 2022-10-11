class Solution {
public:
     int f(int i,int buy,vector<int> &prices,vector<vector<int>>&dp,int n){
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            dp[i][buy]=max(-prices[i]+f(i+1,0,prices,dp,n),f(i+1,1,prices,dp,n));
        }
        else{
            dp[i][buy]=max(+prices[i]+f(i+1,1,prices,dp,n),f(i+1,0,prices,dp,n));
        }
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
        int l=prices.size();
        vector<vector<int>>dp(l,vector<int>(2,-1));
        return f(0,1,prices,dp,l);
    }
//     int rec(vector<int> &a,int i,int n,int buy,vector<vector<int>> dp){
//         if(i==n)return 0;
//         if(dp[i][buy]!=-1)return dp[i][buy];
//         else
//             // (dp[i][buy]==-1)
//         {
//             if(buy){
//                     dp[i][buy]=max(-a[i]+rec(a,i+1,n,0,dp),rec(a,i+1,n,1,dp));
//             }
//             else{
//                     dp[i][buy]=max(a[i]+rec(a,i+1,n,1,dp),rec(a,i+1,n,0,dp));
//             }
//             return dp[i][buy];
//         }
//     }
    
//     int maxProfit(vector<int>& prices) {
//         //DP
//         int n=prices.size();
//         vector<vector<int>> dp(n+1,vector<int>(2,-1));
//         return rec(prices,0,n,1,dp);
        
//         //Greedy
//         // int ans=0;
//         // for(int i=1;i<prices.size();i++){
//         //     if(prices[i]>prices[i-1]){
//         //         ans+=prices[i]-prices[i-1];
//         //         }
//         // }
//         // return ans;
//     }
};