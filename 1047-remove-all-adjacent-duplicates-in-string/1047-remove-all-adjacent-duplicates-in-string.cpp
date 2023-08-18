class Solution {
public:
    string removeDuplicates(string s) {
     stack<char> stk;
        for(auto i:s){
            if(stk.empty() || stk.top()!=i)stk.push(i);
            else stk.pop();
        }
        string str;
        while(stk.size()){str.push_back(stk.top());stk.pop();}
        reverse(str.begin(),str.end());
        return str;
    }
};