class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
       int n=nums.size();
       int ans=0,curr=0;
//         Max +ve Subarray
       for(int i=0;i<n;i++){
           if(curr+nums[i]<0){
               curr=0;
           }
           else curr+=nums[i];
           ans=max(ans,curr);
       }
        
//         Max ive Subarray
        for(auto &i:nums){
            i*=-1;
        }
       curr=0;
       for(int i=0;i<n;i++){
           if(curr+nums[i]<0){
               curr=0;
           }
           else curr+=nums[i];
           ans=max(ans,curr);
       }
        
       return ans;
    }
};