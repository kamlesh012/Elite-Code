class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        int miss,hit;
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end())miss=i;
            if(mp[i]==2)hit=i;
        }
        return vector<int>{hit,miss};
    }
};