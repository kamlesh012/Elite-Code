class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        multiset<int> mst(nums.begin(),nums.end());
        int ans=0;
        
        for(auto i:nums){
            auto it=mst.find(i);
            if(it!=mst.end()){
                mst.erase(it);
                auto req=mst.find(k-i);
                if(req!=mst.end()){
                    mst.erase(req);
                    ans++;
                }
            }
        }
        return ans;
    }
};