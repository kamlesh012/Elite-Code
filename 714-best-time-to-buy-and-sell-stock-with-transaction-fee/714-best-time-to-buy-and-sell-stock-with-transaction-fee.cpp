class Solution {
public:
      int rec(vector<int> &a,int i,int n,int buy,vector<vector<int>>& dp,int fee){
        if(i==n)return 0;
        if(dp[i][buy]==-1)
        {
            if(buy){
                    dp[i][buy]=max(-a[i]+rec(a,i+1,n,0,dp,fee),rec(a,i+1,n,1,dp,fee));
            }
            else{
                    dp[i][buy]=max(a[i]-fee+rec(a,i+1,n,1,dp,fee),rec(a,i+1,n,0,dp,fee));
            }
        }
        return dp[i][buy];
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return rec(prices,0,n,1,dp,fee);
    }
};