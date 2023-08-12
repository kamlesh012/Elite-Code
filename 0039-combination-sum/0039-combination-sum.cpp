class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& cdt, int target) {
        
        /*
        //Brute-Force Recursive Knapsack.  
     vector<vector<int>> master;
        function<void(vector<int> &temp,int i,int sum)> rec=[&](vector<int> &temp,int i,int sum){
            if(sum==0){
                master.push_back(temp);
                return;
            }
            if(i==cdt.size())return;
            //not pick
            rec(temp,i+1,sum);
            
            //pick
            if(cdt[i]<=sum)
            {
                temp.push_back(cdt[i]);
                rec(temp,i,sum-cdt[i]);
                temp.pop_back();
            }
        };
        
        vector<int> temp;
        rec(temp,0,target);
        return master;
        */
        
        //Classical Backtracking Method.
        //Try to visualise in form of levels.
        //for each level a element can be chosen from nums[ind] to nums[n-1]
        
         vector<vector<int>> master;        
        function<void(int ind,vector<int> &temp,int sum)> rec=[&](int ind,vector<int> &temp,int sum){
            if(sum==0){
                master.push_back(temp);
                return;
            }
            if(ind==cdt.size())return;
            
            for(int i=ind;i<cdt.size();i++){
                if(cdt[i]<=sum){
                    temp.push_back(cdt[i]);
                    rec(i,temp,sum-cdt[i]);
                    temp.pop_back();
                }
            }
        };
        
        vector<int> temp;
        rec(0,temp,target);
        return master;
    }
};