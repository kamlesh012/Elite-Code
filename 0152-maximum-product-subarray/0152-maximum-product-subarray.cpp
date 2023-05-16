class Solution {
public:
    int maxProduct(vector<int>& nums) {        
        int mnp=nums[0],mxp=nums[0];
        int ans=mxp;
        for(int i=1;i<nums.size();i++){
            
            // cout<<"MXP "<<mxp<<" MNP"<<mnp<<" ans "<<ans<<endl;
            if(nums[i]<0)swap(mnp,mxp);
            
            mxp=max(nums[i],nums[i]*mxp);
            mnp=min(nums[i],nums[i]*mnp);
            
            ans=max(ans,mxp);
        }
        return ans;
    }
};