class Solution {
public:
    int findMin(vector<int>& a) {
        //         Standard Solution giving fcuks to h=mid,l=mid+1 condition.
        
//       Here the answer might be equal to high, at a point, so high=mid, not high=mid-1.
        //if ans is in high, then doing high=mid might fall in infiinte loop if low==high,
        //so the terminating condition if loop will be low<high not low<=high 
        //as in traditional binary search.
        
        int n = a.size();
        int low = 0;
        int high = n - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
//         The condition a[mid]<a[high] is based on the fact that in a sorted array the next 
            // index element is always greater than the current element,j
//             so if a[mid]<a[high] that means the subarray from mid-high is sorted.
//             & to find the minimum we will check in the left side of mid(including mid).
            if (a[mid] < a[high])
                high = mid;
            else if (a[mid] > a[high])
                low = mid + 1;
        }
        
        return a[low];
        
//         No fcuks given : Invariant Binary Search solution
        /*
        int n=a.size();
        int l=-1,h=n,pivot=-1;
        while(h-l>1){
            int mid=(h-l)/2+l;
            if(a[mid]>a[n-1])l=mid;
            else h=mid;
        }
        return a[h];
        */
    }
};