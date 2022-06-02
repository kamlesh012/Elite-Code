class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')stk.push(s[i]);
            else if( s[i]==')'){
                if(!stk.empty() && stk.top()=='(')stk.pop();
                else stk.push(s[i]);
            }
            else if(s[i]=='}'){
                if(!stk.empty() && stk.top()=='{')stk.pop();
                else stk.push(s[i]);
            }
            else if(s[i]==']'){
                if(!stk.empty() && stk.top()=='[')stk.pop();
                else stk.push(s[i]);
            }
        }
        return stk.empty();
        
    }
};