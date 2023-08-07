class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        int n=s.length();
        unordered_map<string,int> mp;
        
        int i=0;
        string temp;
        vector<string> ans;
        while(i<n && i<10){
            temp.push_back(s[i]);
            i++;
        }
        reverse(temp.begin(),temp.end());
        mp[temp]++;
        while(i<n){
            temp.pop_back();
            temp=s[i]+temp;
            mp[temp]++;
            i++;
        }
        for(auto i:mp){
            if(i.second>1){
                string temp=i.first;
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
        }
        return ans;
        
    }
};