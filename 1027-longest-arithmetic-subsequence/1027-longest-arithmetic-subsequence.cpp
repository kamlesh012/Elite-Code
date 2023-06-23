class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
         //dp[i][j] represents the length of the longest subsequence ending at index i,having common difference (nums[i]-nums[j]).
        
        int n=nums.size(),ans=0;
        //All three declaration resulting in TLE
        // unordered_map<int,unordered_map<int,int>> dp;
        // vector<unordered_map<int,int>> dp(n+1);
        // unordered_map<int,int> dp[1001];
        
        unordered_map<int,vector<int>> dp;
        for(int end=0;end<n;end++){
            for(int j=0;j<end;j++){        
                
                int diff=nums[end]-nums[j];
                //Surprisingly passsing.
                //as allocating a vector of 1's for each index if current diff not found
                //already in dp umap.
                //we won't have to find it again & again using umap.
                //which may be going O(n) in worst case.
                //while vector index access is O(1) always.
                
                if(dp.find(diff)==dp.end()){
                    dp[diff]=vector<int>(1001,1);
                }
                
                //TLE'd: the one with unordered_map
                // if(dp[diff].find(j)==dp[diff].end()){
                //     dp[diff][j]=1;
                // }
                
                dp[diff][end]=max(dp[diff][end],dp[diff][j]+1);
                ans=max(ans,dp[diff][end]);
                
                //TLE'd        
                // int prev=max(1,dp[j][diff]);
                // dp[end][diff]=max(dp[end][diff],prev+1);
                // ans=max(ans,dp[end][diff]);
            }
        }
        return ans;
    }
};