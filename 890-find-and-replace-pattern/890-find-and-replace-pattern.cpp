class Solution {
public:
    bool ismatch(string s,string p){
        map<char,char> mp;
        set<char> st;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end()){
                if(st.find(p[i])!=st.end())return false;
                mp[s[i]]=p[i];
                st.insert(p[i]);
            }
            else {
                if(mp[s[i]]!=p[i])return false;
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       vector<string>ans;
        for(auto i:words){
            if(ismatch(i,pattern)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};