class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n=nums.size();
        
        for(int i=0;i<n-1;i++){
        if(i && nums[i]==nums[i-1])continue;
            
           int j=i+1,k=n-1;        
            while(j<k){
                if((nums[j]+nums[k]+nums[i])<0){
                    j++;
                }
                else if((nums[j]+nums[k]+nums[i])>0){
                    k--;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    
                    while(j<k && nums[j]==nums[j-1])j++;
                    while(j<k && nums[k]==nums[k+1])k--;
                }
                
            }
        }
        
        
        return ans;
    }
};