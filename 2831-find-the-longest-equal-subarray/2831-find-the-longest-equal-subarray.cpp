class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> ind(n+1);
        
        for(int i=0;i<n;i++){
            ind[nums[i]].push_back(i);
        }
        
        int ans=0;
        for(int i=0;i<=n;i++){
            int l=0;
            int r=1;
            if(ind[i].size()){
                int curr=1,total_diff=0;
                while(r<ind[i].size()){
                    int current_difference=ind[i][r]-ind[i][r-1]-1;
                    total_diff+=current_difference;
                    while(l<r && total_diff>k){
                        int sub=ind[i][l+1]-ind[i][l]-1;
                        total_diff-=(sub);
                        l++;
                    }
                    curr=max(curr,r-l+1);
                    r++;
                }
                ans=max(ans,curr);
            }
        }
        
        return ans;
    }
};