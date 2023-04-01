class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Approach is that
        //since all numbers can be from 1 & nums.size()-1 
        //we store the total no. of bits possible at each position range 1->n
        //now since a single number is repeated that means that the bits at the place of 
        //that number will be more than usual.
        //so if we find a situation like that we will take that bit in our ans.
        
        //for the case when the given array contains only a singel number repeated n times
        //and nothing else,that algo will work here too.
        //as the repeated no. will still have the count of bits greater than every no. from 1-n
        //at it's positions.
        //although at other bit positions where other numbers from 1-n lie the bits will be less
        //but we only need to take in consideration where out bits are more than required.not less
        //more means extra bits.
        
        //dry run for the case [2 2 2 2 2] for clarity
        
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