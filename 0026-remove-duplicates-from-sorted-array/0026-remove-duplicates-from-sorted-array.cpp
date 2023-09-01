class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
                nums[j++]=nums[i];
            }
        }
        return st.size();
    }
};