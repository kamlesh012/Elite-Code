class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        int n=nums.size();
        // vector<vector<int>> ans;
        set<vector<int>> master;
        function<void(int i,vector<int>& temp)> rec=[&](int i,vector<int> &temp){    
            if(i==nums.size()){
                // if(temp.size()>=2)ans.push_back(temp);
                if(temp.size()>=2)master.insert(temp);
                return;
            }
            rec(i+1,temp);
            if(temp.empty() || nums[i]>=temp.back()){
                temp.push_back(nums[i]);
                rec(i+1,temp);
                temp.pop_back();
            }
        };
        vector<int> temp;
        rec(0,temp);
        vector<vector<int>> ans(master.begin(),master.end());
        return ans; 
        
    }
};