class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> freq,used;
        int n=s.size();
        for(int i=0;i<n;i++)freq[s[i]]++;
        
        stack<char> stk;
        for(auto i:s){
            freq[i]--;
            if(used[i]==0){
                while(stk.size() && stk.top()>i && freq[stk.top()]){
                    used[stk.top()]--;
                    stk.pop();
                }
                used[i]++;
                stk.push(i);
            }
        }
        
        int k=stk.size();
        string ans(k,'#');
        while(stk.size()){
            ans[--k]=stk.top();
            stk.pop();
        }
        return ans;
    }
};