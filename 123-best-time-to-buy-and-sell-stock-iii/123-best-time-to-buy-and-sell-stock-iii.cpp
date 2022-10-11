class Solution {
public:
    int rec(vector<int> &a,int i,int n,int buy,int k,vector<vector<vector<int>>>& dp){
        if(k==0)return 0;
        if(i==n)return 0;
        if(dp[i][buy][k]==-1)
        {
            if(buy){
                    dp[i][buy][k]=max(-a[i]+rec(a,i+1,n,0,k,dp),rec(a,i+1,n,1,k,dp));
            }
            else{
                    dp[i][buy][k]=max(a[i]+rec(a,i+1,n,1,k-1,dp),rec(a,i+1,n,0,k,dp));
            }
        }
        return dp[i][buy][k];
    }
    
    int maxProfit(vector<int>& prices) {
        //DP
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return rec(prices,0,n,1,2,dp);
        // for(auto i:dp){
        //     for(auto j:i){
        //         for(auto x:j){
        //             cout<<x<<" ";
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
        // }
        // return 0;
        
        //Greedy
        // int ans=0;
        // for(int i=1;i<prices.size();i++){
        //     if(prices[i]>prices[i-1]){
        //         ans+=prices[i]-prices[i-1];
        //         }
        // }
        // return ans;
    }
};