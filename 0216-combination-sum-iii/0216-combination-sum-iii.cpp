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
            //Notice that in each recurisve call we are starting from ind.
            //that means at this level we will choose elemnts in range [ind,n)
            //Try to think of this for loop as the possible elemnts that we can choose at this level/iteration.
            //since in next call we can't take same element next call will start from i+1.
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