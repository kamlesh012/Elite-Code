class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        int n=a.size();
        int l=-1,h=n,ans=-1;
        while(h-l>1){
            int mid=(h-l)/2+l;
            
            if(mid-1>=0 && a[mid]<a[mid-1])h=mid;
            else if(mid+1<n && a[mid]<a[mid+1])l=mid;
            else {l=mid;}
            // else {ans=mid;break;}
            // if(mid-1>=0 && mid+1<n && a[mid]>a[mid+1] && a[mid]<a[mid-1]){
            //     ans=mid;break;
            // }
            
        }
        return l;
    }
};