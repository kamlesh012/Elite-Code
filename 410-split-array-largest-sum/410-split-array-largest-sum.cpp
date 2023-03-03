class Solution {
public:
    //Predicate
    bool predicate(vector<int> &a,int k,int mx){
        int splits=1,sum=0;
        for(int i=0;i<a.size();i++){
            sum+=a[i];
            if(sum>mx){
                splits++;
                sum=a[i];
            }
        }
        return splits<=k;
    }
    
    int splitArray(vector<int>& wt, int k) {
        int n=wt.size();
        
        //Lower-Boundary (Not Inclusive)
        int l=*max_element(wt.begin(),wt.end())-1;
        
        //Upper-Boundary (Not Inclusive)
        int h=accumulate(wt.begin(),wt.end(),0ll)+1;
        
        int ans=-1;
        
        //Invariant Binary Search
        while(h-l>1){
            int mid=((h-l)/2)+l;
            if(predicate(wt,k,mid))h=mid;            
            else l=mid;
        }
        
        return h;
    }
};