class Solution {
public:
    int ans(vector<int>& nums,int i,int j){
        if(i==j)return nums[i];
        if(i>j)return 0;
        int a=nums[i]+min(ans(nums,i+2,j),ans(nums,i+1,j-1));
        int b=nums[j]+min(ans(nums,i+1,j-1),ans(nums,i,j-2));
        return max(a,b);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int one=ans(nums,0,nums.size()-1);
        
        int total=0;
        for(int i:nums)total+=i;
        
        return one>=total-one;
        
        
    }
};