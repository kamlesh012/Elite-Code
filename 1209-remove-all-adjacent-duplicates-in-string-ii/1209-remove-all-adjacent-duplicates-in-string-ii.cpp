class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> stk;
        for(auto i:s){
            if(stk.empty() || stk.top().first!=i)stk.push({i,1});
            else{
                if(stk.top().first==i && stk.top().second==k-1){
                    stk.pop();
                }
                else {
                    auto it=stk.top();
                    stk.pop();
                    it.second++;
                    stk.push(it);
                }
            }
        }
        string ans;
        while(stk.size()){
            auto it=stk.top();
            while(it.second--){
                ans.push_back(it.first);
            }
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};