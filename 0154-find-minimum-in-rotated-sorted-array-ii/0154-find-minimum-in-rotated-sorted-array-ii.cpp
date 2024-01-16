class Solution {
public:
    int findMin(vector<int>& a) {
//         Or check COdeStoryWIthMIK's Search in rotated sorted array-II video.
        
        int n=a.size();
        int l=0,h=n-1;
        while(l+1<n && a[l]==a[l+1])l++;
        
        while(l<h){
            int mid=(h-l)/2+l;
//             way 1
            if(a[mid]<=a[h])h=mid;       //my working condition
            
//             way 2
            // if(a[mid]<a[h])h=mid;           //the next two conditions work as the first one
            // else if(a[mid]==a[h])h--;
            
            else l=mid+1;
        }
        return a[h];
        
    }
};