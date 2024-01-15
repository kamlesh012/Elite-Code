class Solution {
public:
    int search(vector<int>& a, int target) {
        int n=a.size();
        
        int l=-1,h=n,pivot=-1;
        while(h-l>1){
            int mid=(h-l)/2+l;
              //         The condition a[mid]<a[high] is based on the fact that in a sorted array the next 
            // index element is always greater than the current element,j
//             so if a[mid]<a[high] that means the subarray from mid-high is sorted.
//             & to find the minimum we will check in the left side of mid(including mid).
            if(a[mid]<=a[n-1])h=mid;
            else l=mid;
            
            // if(a[mid]>a[n-1])l=mid;
            // else h=mid;
        }
        pivot=h;
        
        if(target>=a[pivot] && target<=a[n-1])l=pivot-1,h=n;
        else l=-1,h=pivot;
        
        
        while(h-l>1){
            int mid=(h-l)/2+l;
          
            if(a[mid]<target)l=mid;
            else h=mid;
        }
        
        if(a[h]!=target)h=-1;
        return h;
        
    }
};