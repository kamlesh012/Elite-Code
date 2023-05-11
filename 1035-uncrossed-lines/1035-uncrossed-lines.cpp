class Solution {
public:
    //LOL What a Fluke!
    int rec(vector<int> &a,vector<int>&b,int i,int j,vector<vector<int>> &dp){
        int n=a.size(),m=b.size();
        if(i>=n || j>=m)return 0;
        if(dp[i][j]==-1){
            if(a[i]==b[j])return dp[i][j]=rec(a,b,i+1,j+1,dp)+1;
            return dp[i][j]=max(rec(a,b,i+1,j,dp),rec(a,b,i,j+1,dp));
        }
        return dp[i][j];
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return rec(nums1,nums2,0,0,dp);
    }
};