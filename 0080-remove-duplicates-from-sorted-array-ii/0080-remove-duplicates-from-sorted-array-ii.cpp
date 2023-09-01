class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        unordered_map<int,int> mp;
        for(auto i:nums){
            if(mp[i]<2){
                mp[i]++;
                nums[j++]=i;
            }
        }
        return j;
    }
};