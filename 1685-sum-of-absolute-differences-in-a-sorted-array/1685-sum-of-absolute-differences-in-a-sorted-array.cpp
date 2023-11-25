class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        
        for(int i=1;i<n;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
    
        vector<int> ans;
        for(int i=0;i<n;i++){
            int prev=0,next=prefix[n-1]-prefix[i];
            if(i){
                prev=abs(prefix[i-1]-(i*nums[i]));
            }
            next-=((n-1-i)*nums[i]);
            // cout<<prev<<" "<<next<<endl;
            ans.push_back(prev+next);
        }
        return ans;
    }
};