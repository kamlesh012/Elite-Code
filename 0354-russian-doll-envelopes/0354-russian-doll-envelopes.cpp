class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n=env.size();
        
        sort(env.begin(),env.end(),[&](vector<int>&a,vector<int> &b){
           if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        
        //O(nlogn) LIS using BS.
        //each index represents the length of the LIS if the element at current index is the end point of a LIS>
        vector<int> take;
        for(auto i:env){
            if(take.empty() || take.back()<i[1]){
                take.push_back(i[1]);
            }
            else{
                //finding the index for this eleemnt whose LIS's endpoint this element can become.
                auto it=lower_bound(take.begin(),take.end(),i[1]);
                int index=(it-take.begin());
                take[index]=i[1];
            }
        }
        return take.size();
        
        //TLE-O(n^2) Classical LIS on Heights after sorting them in decreasing order if same width.
        // vector<int> dp(n+1,1);
        // int ans=1;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(env[i][1]>env[j][1]){
        //             dp[i]=max(dp[i],dp[j]+1);
        //             ans=max(ans,dp[i]);
        //         }
        //     }
        // }
        // return ans;
    }
};