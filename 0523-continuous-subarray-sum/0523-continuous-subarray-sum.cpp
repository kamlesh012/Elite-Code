class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        unordered_map<int,int> mp;
        int prev=nums[0]%k;
        for(int i=1;i<n;i++){
            if(nums[i]%k==0)return true;
            if(mp[nums[i]%k]){
                return true;
            }
            mp[prev]++;
            prev=nums[i]%k;
        }
        return false;
    }
};