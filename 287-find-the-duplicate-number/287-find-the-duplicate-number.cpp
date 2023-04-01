class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=0;
        int bit[32]={0};
        for(int i=1;i<nums.size();i++){
            int x=0;
            while((1<<x)<=i){
                if((1<<x)&i){
                    bit[x]++;
                }
                    x++;
            }
        }
        //  for(auto i:bit){
        //     cout<<i<< " ";
        // }
        // cout<<endl;
        
        int bit2[32]={0};
        for(auto i:nums){
            int x=0;
            while((1<<x)<=i){
                if((1<<x)&i){
                    bit2[x]++;
                }
                x++;
            }
        }
      
        
        // for(auto i:bit2){
        //     cout<<i<< " ";
        // }
        // cout<<endl;
        for(int i=0;i<32;i++){
            if((bit2[i]-bit[i]>0))ans=ans|(1<<i);
        }
        return ans;
        
        
        //Approach if repeated count==1.
        //won't work if count >1
        /*
        int ans=0;
        for(int i=1;i<nums.size();i++){
            ans=(ans^i);
            // cout<<ans<<" ";
        }
        // cout<<endl;
        for(auto i:nums){
            ans=(ans^i);
            // cout<<ans<<" "<<i<<" ";
        }
        // cout<<endl;
        return ans;
        */
    }
};