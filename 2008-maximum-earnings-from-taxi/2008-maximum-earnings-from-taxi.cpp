class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& a) {
         int m=a.size();
        for(int i=0;i<m;i++){
            a[i][2]+=(a[i][1]-a[i][0]);
        }
        
        //Storing starting point of offers in sorted order so that binary search can be applied on this array to get index of required offer.
        //That same index can be use to access the corresponding offer in 2d vector named a.
        sort(a.begin(),a.end());
        
        vector<long long> dp(m,-1);
        vector<int> start;
        
        for(auto i:a){
            start.push_back(i[0]);
        }
        
        function<long long(int i)> rec=[&](int i){
            if(i>=a.size()) return 0ll;
            if(dp[i]!=-1) return dp[i];
            
            long long nopick=rec(i+1);
            int ind=lower_bound(start.begin(),start.end(),a[i][1])-start.begin();
            long long pick=a[i][2]+rec(ind);
            
            return dp[i]=max(pick,nopick);
        };
        long long ans= rec(0);
        return ans;
    }
};