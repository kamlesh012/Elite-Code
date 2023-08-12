class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> master;
        vector<int> cdt(9);
        iota(cdt.begin(),cdt.end(),1);
        
        
        function<void(int ind,vector<int> &temp,int sum,int tk)> rec=[&](int ind,vector<int> &temp,int sum,int tk){
            
            if(sum==0 && tk==0){
                master.push_back(temp);
                return;
            }
            
            if(ind==cdt.size() || k<=0)return;
            
            for(int i=ind;i<cdt.size();i++){
                if(cdt[i]<=sum && tk>0){
                    temp.push_back(cdt[i]);
                    rec(i+1,temp,sum-cdt[i],tk-1);
                    temp.pop_back();
                }
            }
        };
        
        vector<int> temp;
        rec(0,temp,n,k);
        return master;
    }
};