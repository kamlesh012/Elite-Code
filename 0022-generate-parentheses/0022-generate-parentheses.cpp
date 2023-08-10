class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function<void(int,int,string)> rec=[&](int start,int close,string curr){
            if(start<0 || close<0)return;
            if(!start && !close){
                ans.push_back(curr);
                return;
            }
            if(start<=close){
                curr.push_back('(');
                rec(start-1,close,curr);
                curr.pop_back();
            }
            if(close>start){
                curr.push_back(')');
                rec(start,close-1,curr);
                curr.pop_back();
            }
        };
        string temp;
        rec(n,n,temp);
        return ans;
    }
};