class Solution {
public:
    int memo(vector<int> & prices,vector<vector<int>> & dp,int i,int n,int buy){
        if(i>=n)return 0;
        if(dp[i][buy]==-1){
            if(buy){
                dp[i][buy]=max(-prices[i]+memo(prices,dp,i+1,n,0),memo(prices,dp,i+1,n,1));
            }
            else{
            dp[i][buy]=max(prices[i]+memo(prices,dp,i+2,n,1),memo(prices,dp,i+1,n,0));
            }
        }
        return dp[i][buy];
    }
    
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        int ans=memo(prices,dp,0,prices.size(),1);
        // for(auto i:dp)        {
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
        
    }
};