class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
     stack<int> stk;
        int rem=nums.size()-k;
        for(int i=0;i<nums.size();i++){
            if(stk.empty() || stk.top()<=nums[i])stk.push(nums[i]);
            else{
                while(rem>0 && stk.size() && stk.top()>nums[i]){
                    stk.pop();
                    rem--;
                }
                stk.push(nums[i]);
            }
        }
        vector<int> ans(k,0);
        while(stk.size()){
            if(rem==0){
                ans[--k]=stk.top();
            }
            else rem--;
            stk.pop();
        }
        return ans;
    }
};