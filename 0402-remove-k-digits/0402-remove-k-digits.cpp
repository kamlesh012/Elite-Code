class Solution {
public:
    string removeKdigits(string nums, int k) {
        
        stack<char> stk;
        int n=nums.size();
        // if(k==n)return string("0");
        
        for(int i=0;i<n;i++){
            if(stk.empty() || nums[i]>stk.top())
                stk.push(nums[i]);
            else{
                while(k>0 && stk.size() && stk.top()>nums[i]){
                     k--;
                    stk.pop();
                }
                stk.push(nums[i]);
            }
        }
        while(k>0 && stk.size()){stk.pop();k--;}
        
        string ans;
        while(stk.size()){
            ans.push_back(stk.top());
            stk.pop();
        }
        
        // cout<<ans<<endl;
        
        string temp;
        int i=ans.size()-1;
        while(i>0 && ans[i]=='0')i--;
        while(i>=0)temp.push_back(ans[i--]);
        
        if(temp.empty())temp="0";
        return temp;
    }
};