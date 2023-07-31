class Solution {
public:
     vector<int> finalPrices(vector<int>& v) {
        stack<int> s;
        int n=v.size();
        s.push(v.back());
        auto ans=v;
        for(int i=n-2; i>=0; i--){
            while(!s.empty() && s.top()>v[i])
                s.pop();
            if(!s.empty())
                ans[i]-=s.top();
            s.push(v[i]);
        }
        return ans;
    }
};