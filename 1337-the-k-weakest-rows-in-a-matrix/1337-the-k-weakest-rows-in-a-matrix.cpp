class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> sum;
        for(auto i:mat){
            int temp=0;
            for(auto j:i){
                temp+=j;
            }
            sum.push_back(temp);
        }
        
        vector<pair<int,int>> v;
        for(int i=0;i<sum.size();i++){
            v.push_back({sum[i],i});
        }
        
        sort(v.begin(),v.end(),[&](pair<int,int> &a,pair<int,int> &b){
            if(a.first==b.first)  return a.second<b.second;
            return a.first<b.first;  
        });
        
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        
        return ans;
    }
};