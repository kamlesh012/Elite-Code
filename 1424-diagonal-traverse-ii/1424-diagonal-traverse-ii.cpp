class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& a){
        map<int,vector<int>> mp;
        
        int n=a.size();
        int m=0;
        // for(auto &i:a){
        //     int sz=i.size();
        //     m=max(m,sz);
        // }
        
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i<a[j].size())
        //             mp[i+j].push_back(a[j][i]);
        //     }    
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<a[i].size();j++){
                mp[i+j].push_back(a[i][j]);
            }
        }
        
        vector<int> ans;
        for(auto &i:mp){
            vector<int> v=i.second;
            reverse(v.begin(),v.end());
            // for(auto i:v){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            for(auto &j:v){
                ans.push_back(j);
            }
        }
        // reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};