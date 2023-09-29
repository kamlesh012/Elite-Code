class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) {
        int n=s.length();
        
        vector<vector<int>> freq(n,vector<int>(26,0));
        vector<int> prev(60,0);
        
        for(int i=0;i<n;i++){
            freq[i]=prev;
            freq[i][s[i]-'a']++;
            prev=freq[i];
        }
        
        vector<bool> ans;
        for(auto v:q){
            
            int left=v[0],right=v[1],k=v[2];
            int cnt=0,len=right-left+1;
            vector<int> prevf(26,0);
            if(left-1>=0){
                prevf=freq[left-1];
            }
            
            int odd=0;
            for(int i=0;i<26;i++){
                odd+=((freq[right][i]-prevf[i])&1);
            }
            ans.push_back(((2*k)+(len%2))>=odd);
        }
        
        return ans;
        
    }
};