#define mod 1000000007
class Solution {
public:
    vector<vector<int>> dp;
    long long rec(int i,int j,vector<vector<int>> &freq,vector<string> &words,string &target){
        if(j==target.size())return 1;
        if(i==words[0].size())return 0;
        if(dp[i][j]==-1){
            
            long long pick=0ll;
            pick=(((freq[i][target[j]-'a'])%mod)*(rec(i+1,j+1,freq,words,target)%mod))%mod;

            long long notpick=0ll;
            notpick=rec(i+1,j,freq,words,target);
            
            return dp[i][j]=(pick+notpick)%mod;
        }
        return dp[i][j];
    }
    
    int numWays(vector<string>& words, string target) {
        int n=words[0].size();
        vector<vector<int>> freq(n,vector<int>(26,0));
        dp.resize(words[0].size(),vector<int>(target.size(),-1));
        for(auto word:words){
            for(int j=0;j<word.size();j++){
                // cout<<j<<" "<<word[j]<<endl;
                freq[j][word[j]-'a']++;
                // cout<<freq[j][word[j]-'a']<<endl;
            }
        }
        return rec(0,0,freq,words,target);
    }
};