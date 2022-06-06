class Solution {
public:
    vector<vector<int>> master;
    void lc(vector<int> &candidates,int target,int i,vector<int> ans,int n){
        
    if(i>n)return;
    if(target<0)return;
    if(target==0){
        master.push_back(ans);
    }
    if(i>=0 && i<n && target-candidates[i]>=0){
        ans.emplace_back(candidates[i]);
        lc(candidates,target-candidates[i],i+1,ans,n);
        ans.pop_back();
    }
    while(i<n-1 && candidates[i]==candidates[i+1])i++;
    lc(candidates,target,i+1,ans,n);   
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ans;
        int n=candidates.size();
        lc(candidates,target,0,ans,n);
        set<vector<int>>s(master.begin(),master.end());
        vector<vector<int>> sol(s.begin(),s.end());
        return sol;
    }
};