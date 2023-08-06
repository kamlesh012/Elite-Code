#define mod 1000000007
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        //2D Variation of Coin-Change II
            int n=types.size();        
        vector<vector<vector<int>>> dp(51,vector<vector<int>>(51,vector<int>(target+1,-1)));
        function<int(int,int,int)> rec=[&](int i,int current,int sum){
            if(sum==0)return 1;
            if(i==n)return 0;
            int &ans=dp[i][current][sum];
            if(ans!=-1)return ans;
            
            int skip=rec(i+1,0,sum);
            int pick=0;
            if(current<types[i][0] && sum>=types[i][1])pick=rec(i,current+1,sum-types[i][1]);
            return ans=((skip%mod)+(pick%mod))%mod;
        };
        
        return rec(0,0,target);
        
/*
//Iterative Pending


        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(51,vector<int>(target+1,0)));
        int sol=0;
        for(int i=0;i<=n;i++){
            for(int c=0;c<51;c++){
                for(int j=0;j<=target;j++){
                    if(j==0)dp[i][c][j]=1;
                    else if(i==0 || c==0)dp[i][c][j]=0;
                    else{
                        dp[i][c][j]=dp[i-1][0][j];
                        
                        if(c<types[i-1][0] && j>=types[i-1][1])
                            dp[i][c][j]=(dp[i][c][j]%mod+dp[i][c+1][j-types[i-1][1]]%mod)%mod;
                        sol=max(sol,dp[i][c][j]);
                    }
                }
            }
        }
        return sol;
        
        */
    }
};