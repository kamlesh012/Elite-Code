class Solution {
public:
       //Read Official Editorial for Clarificatiosn.
        //Dry Run on Both Sample TCs more than enough to get the idea.What I am doing.
    int numberOfArithmeticSlices(vector<int>& nums) {
      int n=nums.size(),ans=0;
        vector<unordered_map<long long,long long>> dp(n+1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                
                long long diff=(long long)nums[i]-(long long)nums[j];
                
                //Stores count of all arithmetic subsequnces(length at least 2)
                dp[i][diff]+=dp[j][diff]+1;
                
                //but we need subsequences of length>2. so  will not include
                //the newest subsequence formed{nums[j],nums[i]} as it is of length 2;
                //but it will be stored in dp as subsequences of length 2 are counted for future use.
                ans+=dp[j][diff];
                
            }
        }
        return ans;
        
    }
};