class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        int n=s.length();
        unordered_map<string,int> mp;
        for(auto i:dict)mp[i];
        vector<int> dp(301,0);
        dp[n]=1;
        for(int i=n-1;i>=0;--i){
            string temp;
            for(int j=i;j<n;j++){
                temp.push_back(s[j]);
                dp[i]=dp[i] | (mp.count(temp) && dp[j+1]);
            }
        }
        return dp[0];
    }
};