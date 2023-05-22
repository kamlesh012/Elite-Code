class Solution {
public:
    bool predicate(vector<int> &nums,int k){
        for(auto i:nums){
            k+=i;
            if(k<1)return false;
        }
        return true;
    }
    
    int minStartValue(vector<int>& nums) {
        int l=0,h=1e9;
        while(h-l>1){
            int mid=(h-l)/2+l;
            if(predicate(nums,mid)){
                h=mid;
            }
            else l=mid;
        }
        return h;
    }
};