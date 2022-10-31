class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1,ans=0;
        while(l<=r){
            int mid=((r-l)/2)+l;
            if(nums[mid]>=nums[0] && nums[mid]>nums[n-1])l=mid+1;
            else {ans=mid;r=mid-1;}
        }
        return nums[ans];
    }
};