class Solution {
public:
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>> a;
        for(int i=0;i<n;i++){
            a.push_back({start[i],end[i],profit[i]});
        }
        sort(a.begin(),a.end());
        vector<int> dp(a.size()+1,-1);
        
        //Storing starting point of offers in sorted order so that binary search can be applied on this array to get index of required offer.
        //That same index can be use to access the corresponding offer in 2d vector named a.
        // vector<int> start;
        // for(auto i:a){
        //     start.push_back(i[0]);
        // }
        sort(start.begin(),start.end());
        function<int(int i)> rec=[&](int i){
            if(i>=a.size()) return 0;
            if(dp[i]!=-1) return dp[i];
            
            int nopick=rec(i+1);
            int ind=lower_bound(start.begin(),start.end(),a[i][1])-start.begin();
            int pick=a[i][2]+rec(ind);
            
            return dp[i]=max(pick,nopick);
        };
        
        return rec(0);
    }
};