class Solution {
public:
    bool wordBreak(string s, vector<string>& wd) {
        
        unordered_map<string,int> mp;
        for(auto i:wd){
            mp[i]++;
        }
        int n=s.size();
        // vector<bool> dp(n+1,0);
        // dp[n]=true;
        // for(int start=n-1;start>=0;--start){
        //     string temp;
        //     for(int end=start;end<n;end++){
        //         temp.push_back(s[end]);
        //         bool found=mp.count(temp);
        //         dp[start]=dp[start]|(found && dp[end+1]);
        //     }
        // }
        // return dp[0];
        
      // DP[i] represents whether the substring  starting at position is valid or not.
        vector<int> dp(n,-1);
        function<int(int)> rec=[&](int i){
            if(i==n)return 1;
            if(dp[i]==-1){
                dp[i]=0;
                string temp;
              for(int j=0;j+i<n;j++){
                  temp.push_back(s[i+j]);
                  int found=mp.count(temp);
                  dp[i]|=(found&rec(i+j+1));
              }
            }
            return dp[i];
        };
        return rec(0);
    }
};