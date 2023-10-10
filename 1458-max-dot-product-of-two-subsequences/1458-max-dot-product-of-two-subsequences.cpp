class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j)
    {
        if(i == nums1.size() || j == nums2.size())
            return INT_MIN;
        
        if(dp[i][j] != 0)
            return dp[i][j];
        
        int res = solve(nums1, nums2, i + 1, j);
        res = max(res, solve(nums1, nums2, i, j + 1));
        
        res = max(res, nums1[i] * nums2[j] + max(0, solve(nums1, nums2, i + 1, j + 1)));
        
        return dp[i][j] = res;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, 0, sizeof dp);
        return solve(nums1, nums2, 0, 0);
        
    }
};