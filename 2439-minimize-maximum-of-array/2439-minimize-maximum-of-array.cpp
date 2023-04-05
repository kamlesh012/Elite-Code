class Solution {
public:
    bool isMaxPossible(vector<int> &a,int mid){
        //Observation is that we can decrease an element i by x
        //only if we could increase all values before i by atleast x
        
        //Using that observation I am trying to check whether 
        //all elements can be at max mid or not.
        
        long long have=0ll;
        // cout<<mid<<endl;
        for(int i=0;i<a.size();i++){
            // cout<<a[i]<<" "<<mid<<" "<<have<<endl;
            if(a[i]<mid){
                //if an element is smaller than mid than I can increase it to mid by mid-a[i]
                
                //that means i can use this value(mid-a[i]) while decreasing some other no. after this index.
                
                have+=(mid-a[i]);
            }
            else{
                //here if an element is greater than mid ,we need to decrease it.
                //we can only decrease if we have the ability to decrease a[i]-mid values from 
                //any of  the elements before this index.
                
                //if we don't have the ability we will return false;
                
                if((a[i]-mid)>have)return false;
                //if we can reduce this no. of operations.
                have-=(a[i]-mid);
            }
        }
        return true;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        int l=-1,h=1e9+1;
        while(h-l>1){
            int mid=(h-l)/2+l;
            if(isMaxPossible(nums,mid))h=mid;
            else l=mid;
        }
        return h;
    }
};