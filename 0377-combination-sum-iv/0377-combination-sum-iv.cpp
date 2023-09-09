class Solution {
public:
    int combinationSum4(vector<int>& nums, int k) {
        int n=nums.size();
        int dp[1001];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;

        for (int i = 1; i <= k; i++) {
            long long ans = 0ll;
            for (int j = 1; j <= n; j++) {
                if (i - nums[j - 1] >= 0)ans += dp[i - nums[j - 1]];
            }
            dp[i] = ans;
        }
    return dp[k];
        }
};