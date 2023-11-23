class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=nums.size();
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            int start=l[i],end=r[i];
            vector<int> temp;
            for(int z=start;z<=end;z++){
                temp.push_back(nums[z]);
            }
            sort(temp.begin(),temp.end());
            bool ok=true;
            if(temp.size()>1){
                int diff=temp[1]-temp[0];
                for(int i=2;i<temp.size();i++){
                    if(temp[i]-temp[i-1]!=diff){
                        ok=false;
                        break;
                    }
                }    
            }
            ans.push_back(ok);
        }
        return ans;
    }
};