class Solution {
public:
/*     below is my understanding,

k is only determined by people with equal or larger height, so makes sense to insert in non-increasing order of height. Because when we insert some person with height h and count k, we know that we have found its correct position relative to people with equal and larger height. And when we later insert other people with equal or smaller height, we know that it will not affect this relative position. So the answer is right after we insert all people.
*/
    vector<vector<int>> reconstructQueue(vector<vector<int>>& peeps){
        
          sort(peeps.begin(),peeps.end(),[&](vector<int> a,vector<int> b){
              return (a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]));
          });
        
        vector<vector<int>> ans;
        for(auto i:peeps){
            // cout<<i[0]    <<" "<<i[1]<<endl;
            ans.insert(ans.begin()+i[1],i);
        }
        return ans;
    }
};