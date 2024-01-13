class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.length();
        map<char,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        int ans=0;
        for(auto i:t){
            if(mp.find(i)!=mp.end()){
                mp[i]--;
                if(mp[i]==0)mp.erase(i);
            }
            else ans++;
        }
        return ans;
    }
};