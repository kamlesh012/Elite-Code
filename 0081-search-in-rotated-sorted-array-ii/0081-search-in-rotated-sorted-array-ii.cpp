class Solution {
public:
    bool search(vector<int>& a, int target) {
        //Skipping Duplicates on Boundaries that might cause problems in eliminating wrong search space.
        
//         This is a Joke code.
//         Joke of Invairant Binary Search
        int l=0,h=a.size()-1,n=a.size();
        
        //Check KnockCat's solution in discuss for a more Convincing & Standard Solution.
        while(l+1<n && a[l]==a[l+1])l++;
        while(h>l && a[h]==a[l])h--;
        
//      Case when all elements are equal.
        if(a[h]==a[l]){
            return a[h]==target;
        }
        
        //NOn Standard BS Invariant :Code for Search in a Rotated Sorted Array-I
        int pivot=-1;
        while(h-l>1){
            int mid=(h-l)/2+l;
            if(a[mid]>a[n-1])l=mid;
            else h=mid;
        }
        pivot=h;
        
        if(target>=a[pivot] && target<=a[n-1])l=pivot-1,h=n;
        else l=-1,h=pivot;
        
        while(h-l>1){
            int mid=(h-l)/2+l;
            if(a[mid]<target)l=mid;
            else h=mid;
        }
        
        if(a[h]!=target)return false;
        else return true;
    }
};