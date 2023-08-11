class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> num(n);
        iota(num.begin(),num.end(),1);
        vector<vector<int>> ans;
        
     function<void(int i,int left,vector<int> &temp)> knapsack=[&](int i,int left,vector<int> temp){
         if(!left){
             ans.push_back(temp);
             return;
         }
         if(i==n)return;
         
         knapsack(i+1,left,temp);
         
             
         temp.push_back(num[i]);
            knapsack(i+1,left-1,temp);
            temp.pop_back();
     };
        vector<int> temp;
        knapsack(0,k,temp);
        return ans;
    }
};