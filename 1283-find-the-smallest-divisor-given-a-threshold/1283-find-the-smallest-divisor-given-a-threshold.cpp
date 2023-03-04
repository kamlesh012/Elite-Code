class Solution {
public:
    bool predicate(vector<int>& nums,int threshold,int k){
        int sum=0;
        for(auto i:nums){
            sum+=(i-1)/k+1;
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=0,h=1e7;
        while(h-l>1){
            int mid=(h-l)/2+l;
            if(predicate(nums,threshold,mid))h=mid;
            else l=mid;
        }
        return h;
    }
};