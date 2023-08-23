class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size(),k=2;
        sort(events.begin(),events.end());
        vector<int> start;
        for(auto i:events){
            start.push_back(i[0]);
        }
        
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        function<int(int i,int tempk)> rec=[&](int i,int tempk){
            if(i>=n)return 0;
            if(tempk==0)return 0;
            if(dp[i][tempk]!=-1)return dp[i][tempk];
            
            int notpick=rec(i+1,tempk);
            int ind=upper_bound(start.begin(),start.end(),events[i][1])-start.begin();
            int pick=events[i][2]+rec(ind,tempk-1);
            return dp[i][tempk]=max(pick,notpick);
        };
        
        return rec(0,k);
    }
};