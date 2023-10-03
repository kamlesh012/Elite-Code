class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> arr(101,0);
        int ans=0;
        for(auto i:nums)ans+=arr[i]++;
        return ans;
    }
};