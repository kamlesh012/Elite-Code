class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& grp) {
        int n=grp.size();
        vector<vector<vector<int>>> mp(n+1,vector<vector<int>>());
        for(int i=0;i<n;i++){
            if(mp[grp[i]].empty() || mp[grp[i]].back().size()==grp[i]){
                mp[grp[i]].push_back(vector<int>{i});
            }
            else if(mp[grp[i]].back().size()<grp[i]){
                mp[grp[i]].back().push_back(i);
            }
        }
        vector<vector<int>> ans;
        for(auto i:mp){
            for(auto j:i){
                ans.push_back(j);
            }
        }
        return ans;
    }
};