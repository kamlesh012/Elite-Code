class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto i:s){
            if(i=='c'){
                char one='#',two='#';
                if(stk.empty())return false;
                else {one=stk.top();stk.pop();}
                if(stk.empty())return false;
                else {two=stk.top();stk.pop();}
                if(two=='a' && one=='b')continue;
                else return false;
            }
            else stk.push(i);
        }
        return stk.empty();
    }
};