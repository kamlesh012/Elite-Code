class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
           // vector<vector<int>> ans;
        set<vector<int>> master;
        //Standard BackTracking Approach-2
        //Here in this approach we will swap each element of nums with a specific index (say ind) once & in next recursive call we will start from the index ind+1 so that we don't swap back the values we swapped in previous recursive call.
        
        function<void(int ind)> rec=[&](int ind){
            if(ind==nums.size()){
                // ans.push_back(nums);
                master.insert(nums);
                return;
            }
            //Remember to start i from ind always so that we don't swap values back
            for(int i=ind;i<nums.size();i++){
                swap(nums[i],nums[ind]);
                rec(ind+1);
                swap(nums[i],nums[ind]);
            }
        };
        rec(0);
        vector<vector<int>> ans(master.begin(),master.end());
        return ans;
    }
};