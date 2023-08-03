class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        map<char,int> freq,used;
        for(auto i:s){
            freq[i]++;
        }
        stack<char> stk;
        
        for(int i=0;i<n;i++){
            freq[s[i]]--;
            
            //if current character is already used in the string that means that
            //it is at its best possible place because the stack is monotonically increasing.
            //if in future it's place becomes not the best,then the characters after it will pop it out & it will find it's new best place when encountered again.
            if(used[s[i]])continue; 
            
            while(stk.size() && stk.top()>s[i] && freq[stk.top()]>0){
                used[stk.top()]--;
                stk.pop();
            }
            used[s[i]]++;
            stk.push(s[i]);
        }
        
        string ans;
        while(stk.size()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};