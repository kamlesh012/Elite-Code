#define mod 1000000007
class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        
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
    }
};