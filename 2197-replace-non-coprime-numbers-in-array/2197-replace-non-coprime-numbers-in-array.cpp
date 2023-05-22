class Solution {
public:
    long long lcm(long long a,long long b){
        return (a*b*1ll)/__gcd(a,b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
       stack<int> stk;
        for(auto i:nums){
            
            if(stk.empty() || __gcd(stk.top(),i)==1){
                stk.push(i);
            }
            else{
                int current=i;
                
                //Keep matching with previous elements as well.
                //Understood from Chandan Agarwal's SOlution.
                while(stk.size() && __gcd(stk.top(),current)>1){
                    current=(lcm(current,stk.top()));
                    stk.pop();
                }
                stk.push(current);
            }
        }
        vector<int> ans;
        while(stk.size()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};