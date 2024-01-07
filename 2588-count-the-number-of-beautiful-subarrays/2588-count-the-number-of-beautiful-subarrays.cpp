class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        
        long long ans=0,sum=0;
        
        unordered_map<int,int> mp;
        mp[0]++;
        
        for(int i=0;i<nums.size();i++){
            sum^=nums[i];
            ans+=mp[sum]++;
        }
        
        return ans;
    }
};