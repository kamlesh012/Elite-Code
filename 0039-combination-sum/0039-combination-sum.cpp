class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& cdt, int target) {
        
     vector<vector<int>> master;
        function<void(vector<int> temp,int i,int sum)> rec=[&](vector<int> temp,int i,int sum){
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
    }
};