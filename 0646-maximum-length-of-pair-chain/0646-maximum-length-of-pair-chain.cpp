class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        //LIS Variation.
        
        sort(pairs.begin(),pairs.end(),[&](vector<int> &a,vector<int> &b){
            // if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        
        int n=pairs.size(),ans=1;
        vector<int> lis(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    lis[i]=max(lis[i],lis[j]+1);
                    ans=max(ans,lis[i]);
                }
            }
        }
        return ans;
    }
};