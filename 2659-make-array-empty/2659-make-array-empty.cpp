class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        
        //Coulnd't implement myself.
        //Left a basic observation, due to which couldn't  implement.
        //could have used ans=n before.
        //to skip from the case of processing the last element.
        
        // int mx=*max_element(nums.begin(),nums.end());
        long long int ans=n,prev=0ll,taken=0ll,currtaken=0;
        for(auto i:mp){
            // if(i.first==mx){
            //     ans+=(n-taken);
            // }
            // else 
                if(i.second<prev){
                ans+=n-(taken);
                currtaken=taken;
                taken++;
            }
            else taken++;
            // if(prev==0){
            //     ans+=i.second;
            //     taken++;
            // }
            // else if(i.second>prev){
            //     // ans+=i.second-prev-currtaken;
            //     ans+=i.second-prev;
            //     taken++;
            // }
            // else{
            //     currtaken=taken;
            //     ans+=i.second-taken;
            //     taken++;
            // }
            prev=i.second;
            
        }
        // if(ans==0)ans=n;
        return ans;
    }
};