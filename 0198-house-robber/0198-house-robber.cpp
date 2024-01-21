class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        function<int(int i)> memo=[&](int i){
            if(i>=n)return 0;
            if(dp[i]!=-1)return dp[i];
            
            int pick=nums[i]+memo(i+2);
            int notpick=memo(i+1);
            return dp[i]=max(pick,notpick);
        };
        return memo(0);
    }
};