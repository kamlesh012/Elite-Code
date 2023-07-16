class Solution {
public:
    int maximumBeauty(vector<int>& a, int k) {
        //Thanks Mukul-Rawat for this clean Approach.
        //the main observation if that
        //in a sorted subarray of size x
        // if max possible value of first element intersects with least possible value of xth element then this window is valid. as all the elements in b/w will also satisfy this condition.
        //Formally ((1st element + k) >=( xth element - k)) must be true;
        //using binary search on answer to maximize this subarray
        
        int n=a.size();
        sort(a.begin(),a.end());
        int l=-1,h=n;
        
        while(h-l>1){
            bool ok=false;    
            int mid=(h-l)/2+l;
            for(int i=mid;i<n;i++){
                if((a[i-mid]+k)>=a[i]-k){
                    ok=true;
                    break;
                }
            }
            if(ok)l=mid;
            else h=mid;
        }
        return l+1;
        ///could be done using plane sliding window in O(n) as well.
        
    }
};