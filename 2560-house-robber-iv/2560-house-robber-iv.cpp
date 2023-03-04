class Solution {
public:
    //Predicate to test if it is possible to steal at least k houses with the max amount of money smaller than or equal to mx.
    
    bool predicate(vector<int>& nums,int k,int mx){
        for(int i=0;i<nums.size();i++){
            
            //if current house has money less than mx,pick it. because there is no max limit on the no. of houses we can steal. stealing extra houses won't do any harm .But we won't be able to pick the next one.
            if(nums[i]<=mx){
                //if picked current house:
                
                //Count of Min Houses to rob will decrease by one.
                k--;
                
                //Skipping the next house
                i++;
            }
            //if k houses have been picked we return that it is possible
            if(k==0)return true;
        }
        
        //else not possible
        return false;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,h=1e9+1;
        while(h-l>1){
            int mid=(h-l)/2+l;
            if(predicate(nums,k,mid))h=mid;
            else l=mid;
        }
        return h;
    }
};