class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(auto i:tasks)mp[i]++;
        int ans=0;
        
        for(auto i:mp){
            int curr=i.second;
            if(curr==1)return -1;
            if(curr%3==0)ans+=curr/3;
            else ans+=(curr/3)+1;
        }
        return ans;
    }
};