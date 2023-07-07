class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i=0,j=0,n=nums.size(),sum=0,len=INT_MAX;
        
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                len=min(len,j-i+1);
                // cout<<j<<" "<<i<<" length "<<len<<endl;
                // cout<<"INside sum "<<sum<<endl;
                sum-=nums[i];
                i++;
            }
            j++;
            // cout<<"SUM "<<sum<<endl;
            // cout<<"i "<<i<<" j "<<j<<endl;
        }
        
        return (len==INT_MAX)?0:len;
    }
};