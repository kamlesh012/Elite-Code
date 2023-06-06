class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)return 0;
        else{
            int curr=nums[1]-nums[0];
            int cnt=0,ans=0,inc=1;
            for(int i=2;i<n;i++){
                int diff=nums[i]-nums[i-1];
                // cout<<nums[i-1]<<" "<<nums[i]<<endl;
                // cout<<diff<<" "<<curr<<" "<<cnt<<endl;
                if(diff==curr){
                    cnt+=inc;
                    inc++;
                }
                else{
                    curr=diff;
                    ans+=cnt;
                    cnt=0;
                    inc=1;
                }
            }
            ans+=cnt;
            return ans;
        }
    }
};