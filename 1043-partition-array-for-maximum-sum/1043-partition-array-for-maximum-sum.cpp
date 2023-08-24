class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       int n=arr.size();
        vector<int> dp(n+1,0);

        // function<int(int)> rec=[&](int i){
            // if(i>=n)return 0;
            // if(dp[i]!=-1)return dp[i];
            for(int i=n-1;i>=0;--i){
                int mx=i;
                for(int j=i;j<min(i+k,n);j++){
                    if(arr[j]>=arr[mx])mx=j;
                    dp[i]=max(dp[i],(j-i+1)*arr[mx]+dp[j+1]);    
                    // dp[i]=max(dp[i],(j-i+1)*arr[mx]+rec(j+1));    
                }
            }
            // return dp[i];
        // };
        // return rec(0);
        return dp[0];
        
    }
};