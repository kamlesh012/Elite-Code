class Solution {
public:
    int maxNonDecreasingLength(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<vector<int>> dp(n+1,vector<int>(2,1));
        
//         function<int(int i,int prev)> rec=[&](int i,int last){
//             if()    
//                 int lastone=0,lasttwo=0;
//                 if(last==0)lastone=a[i-1];
//                 else if(last==1)lastone=b[i-1];
//                 int firstpick=
            
//         };
        int ans=1;
        for(int i=1;i<n;i++){
            int prev1=0,prev2=0;
            // if(i-1>=0)
                prev1=a[i-1];
            // if(i-1>=0)
                prev2=b[i-1];
            // cout<<a[i]<<" val "<<b[i]<<endl;
            // cout<<prev1<<" prev "<<prev2<<endl;
            if(a[i]>=prev1)dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
            // else dp[i][0]=max(dp[i][0],1);
            
            if(a[i]>=prev2)dp[i][0]=max(dp[i][0],dp[i-1][1]+1);
            // else dp[i][0]=max(dp[i][0],1);
            
            if(b[i]>=prev1)dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
            // else dp[i][1]=max(dp[i][1],1);
            
            if(b[i]>=prev2)dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
            // else dp[i][1]=max(dp[i][1],1);
            
            ans=max(ans,dp[i][0]);
            ans=max(ans,dp[i][1]);
            // cout<<i<<"  "<<dp[i][0]<<" "<<dp[i][1]<<endl;
        }
        return ans;
    }
};