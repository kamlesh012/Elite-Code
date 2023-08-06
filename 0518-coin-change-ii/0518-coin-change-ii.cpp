class Solution {
public:
    //Coin Combinations-II [CSES]
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        
        function<int(int,int)> rec=[&](int i,int sum){
            if(sum==0)return 1;
            if(i==n)return 0;
            
            if(dp[i][sum]==-1)
            {
                int pick=0,notpick=0;
                
                //Skip current Coin
                notpick=rec(i+1,sum);
                
                //Keep Choosing current coin till we can.
                if(coins[i]<=sum)pick=rec(i,sum-coins[i]);
                
                dp[i][sum]=pick+notpick;
            }
            return dp[i][sum];
        };
        
        return rec(0,amount);
        
        }
};