class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=-1,h=nums.size();
        while(h-l>1){
            int mid=(h-l)/2+l;
            if(nums[mid]>=target)h=mid;
            else l=mid;
        }
        if(h==nums.size() || nums[h]!=target)h=-1;
        return h;
    }
};