class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& cdt, int target) {
        vector<vector<int>> master;
        sort(cdt.begin(),cdt.end());
        
        function<void(int ind,vector<int> &temp,int sum)> rec=[&](int ind,vector<int> &temp,int sum){
            if(sum==0){
                master.push_back(temp);
                return;
            }
            if(ind==cdt.size())return;
            
            for(int i=ind;i<cdt.size();i++){
                
                //if a equal element has been taken at this level
                //then skip it.
                if(i>ind && cdt[i]==cdt[i-1])continue;
                //notice here that i>ind. it means that if I am at the start of a level & has already taken previous element then skip it.
                // but if I am at a fresh level then duplicates might be considered ,this will be the case in which a element is more than once in the answer because it is more than once in original permutation.
                //DRY run on nums=[1 1 1 2 3] target=3 to understand this cleve skiping better.
                //&  understand why i==ind is not done. it will skip duplicates in current permutation as well for example 1 1 1 is a possible answer but i==ind will not allow it to happen.
                
                //although i>ind will allow it as 1 will be skipped to be chose at current level if already chosen ,but at next level/iteration it will be allowed to be chosen.
                
                
                if(cdt[i]<=sum){
                    temp.push_back(cdt[i]);
                    rec(i+1,temp,sum-cdt[i]);
                    temp.pop_back();
                }
            }
        };
        
        vector<int> temp;
        rec(0,temp,target);
        return master;
    }
};