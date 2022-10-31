class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=((r-l)/2)+l;
            if(nums[mid]>=nums[0] && nums[mid]>nums[n-1])l=mid+1;
            else r=mid-1;
        }
        
        l=0;
        int h=r,ans=-1;
        while(l<=h){
            int mid=((h-l)/2)+l;
            if(nums[mid]>target)h=mid-1;
            else {
                ans=mid;
                l=mid+1;
            }
        }
        
        if(ans>=0 && ans<n && nums[ans]==target)return ans;
        l=r+1;
        h=n-1;
        
        while(l<=h){
            int mid=(h-l)/2+l;
            if(nums[mid]>target)h=mid-1;
            else {
                ans=mid;
                l=mid+1;
            }
        }
        if(ans>=0 && ans<n && nums[ans]==target)return ans;
        return -1;
    }
};