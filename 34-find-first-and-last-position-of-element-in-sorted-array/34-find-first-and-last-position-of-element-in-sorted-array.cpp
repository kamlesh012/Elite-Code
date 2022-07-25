class Solution {
public:
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1,ans1=-1,ans2=-1;
        
        if(!nums.empty()){
            while(l<=h){
                int m=(h-l)/2+l;
                if(nums[m]==target){
                    ans1=m;
                    h=m-1;
                }
                else if(nums[m]>target){
                    h=m-1;
                }
                else l=m+1;
            }

            l=0;h=nums.size()-1;

            while(l<=h){
                int m=(h-l)/2+l;
                if(nums[m]==target){
                    ans2=m;
                    l=m+1;
                }
                else if(nums[m]>target){
                    h=m-1;
                }
                else l=m+1;
            }
    }
        vector<int> v;
        v.push_back(ans1);
        v.push_back(ans2);
        return v;
    }
};