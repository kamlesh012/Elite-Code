class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        long long int i=0,csum=0ll,tsum=0ll;
        unordered_set<int> st;
        
        vector<int> freq(100001,0);
        while(i<k){
            freq[nums[i]]++;
            st.insert(nums[i]);
            csum+=nums[i];
            i++;
        }
        if(st.size()==k)tsum=csum;
        
        while(i<n){
            st.insert(nums[i]);
            csum+=nums[i];
            freq[nums[i]]++;
            
            freq[nums[i-k]]--;
            csum-=nums[i-k];
            if(freq[nums[i-k]]==0)st.erase(nums[i-k]);
            
            if(st.size()==k)tsum=max(tsum,csum);
            i++;
        }
        
        return tsum;
    }
};