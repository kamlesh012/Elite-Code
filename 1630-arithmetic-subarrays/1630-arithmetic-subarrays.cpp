class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=l.size();
        vector<bool> ans;
        for(int i=0;i<n;i++){
            
            int start=l[i],end=r[i];
            vector<int> v;
            for(int j=start;j<=end;j++)v.push_back(nums[j]);
            
            sort(v.begin(),v.end());
            int diff=v[1]-v[0];
            bool ok=true;
            
            for(int j=1;j<end-start+1;j++){
                if((v[j]-v[j-1])!=diff){
                    ok=false;
                    break;
                }
            }
            
            ans.push_back(ok);
        }
        return ans;
        
    }
};