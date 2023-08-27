class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        
        function<int(int i,int prev)> rec=[&](int i,int prev){
            if(i==(n-1)){
                return 1;
            }
            if(i>=n){
                return 0;
            }
            
            if(dp[i][prev]!=-1){
                return dp[i][prev];
            }
            
            int diff=stones[i]-stones[prev];
            int possible=0;
            auto it=lower_bound(stones.begin(),stones.end(),(stones[i]+(diff-1)));
            if(it!=stones.end() && (*it==(stones[i]+diff-1))){
                int ind=it-stones.begin();
                if(ind!=i)possible|=rec(ind,i);
              }
            
            
            it=lower_bound(stones.begin(),stones.end(),(stones[i]+(diff)));
              if(it!=stones.end() && (*it==(stones[i]+diff))){
                int ind=it-stones.begin();
                if(ind<n)possible|=rec(ind,i);
              }
            
            it=lower_bound(stones.begin(),stones.end(),(stones[i]+(diff+1)));
              if(it!=stones.end() && (*it==(stones[i]+diff+1))){
                int ind=it-stones.begin();
                if(ind<n)possible|=rec(ind,i);
              }
            
            return dp[i][prev]=possible;
        };
        
        if(stones[1]!=1)return false;
        return rec(1,0);
    }
};