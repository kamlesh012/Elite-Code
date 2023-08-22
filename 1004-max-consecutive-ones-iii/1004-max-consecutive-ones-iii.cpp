class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int remove=0;
        int ans=0,j=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)remove++;
            while(j<i && remove>k){
                if(nums[j]==0)remove--;
                j++;
            }
            //handle cases when k=0 or there is no 1 in nums.
            if(remove<=k)ans=max(ans,i-j+1);
        }
        
        return ans;
    }
};