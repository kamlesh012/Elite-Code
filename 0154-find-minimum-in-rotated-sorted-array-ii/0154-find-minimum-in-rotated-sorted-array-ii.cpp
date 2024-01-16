class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        int l=0,h=n-1;
        while(l+1<n && a[l]==a[l+1])l++;
        // while(h>l && a[h]==a[h-1])h--;
        
        while(l<h){
            int mid=(h-l)/2+l;
            if(a[mid]<=a[h])h=mid;
            else l=mid+1;
        }
        return a[h];
        
    }
};