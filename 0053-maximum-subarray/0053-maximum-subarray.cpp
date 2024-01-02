class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0,mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(curr+nums[i]>=nums[i]){
                curr+=nums[i];
            }
            else curr=nums[i];
            mx=max(mx,curr);
        }
        return mx;
    }
};