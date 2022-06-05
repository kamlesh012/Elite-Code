class Solution {
public:
vector<vector<int>> master;
    void lc(vector<int> &candidates,int target,int i,vector<int> ans){        
    if(i>=candidates.size())return;
    if(target==0){master.push_back(ans);return;}
    if(target<0)return;
    
    if(target-candidates[i]>=0){
        ans.push_back(candidates[i]);
        lc(candidates,target-candidates[i],i,ans);
        ans.pop_back();
    }
    lc(candidates,target,i+1,ans);
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        lc(candidates,target,0,ans);
        return master;
        
    }
};