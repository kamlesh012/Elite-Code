class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        int n=s.length();
        vector<int> dp(51,1e9);
        unordered_map<string,int> mp;
        for(auto i:dict){
            mp[i]++;
        }
        
        //Base Case
        dp[n]=0;
        
        for(int i=n-1;i>=0;--i){
            string temp;
            for(int j=i;j<n;j++){
                temp.push_back(s[j]);
                dp[i]=min(dp[i],!mp.count(temp)*(j-i+1)+dp[j+1]);
            }
        }
        return dp[0];
    }
};