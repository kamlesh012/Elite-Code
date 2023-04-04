class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        int last=INT_MIN;
        int start=0,cnt=1,ans=0;
        for(auto i:mp){
            // cout<<i.first<<" - "<<endl;
            if(start){
                if(i.first-last==1){
                    cnt++;
                    // cout<<i.first<<" "<<last<<endl;
                }
                else cnt=1;
               
                    last=i.first;
            }
            else {
                last=i.first;
                  start++;
            }
             ans=max(ans,cnt);
        }
        return ans;
    }
};