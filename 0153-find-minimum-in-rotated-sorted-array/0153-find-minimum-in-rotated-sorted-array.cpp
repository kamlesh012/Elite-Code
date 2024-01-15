class Solution {
public:
    int findMin(vector<int>& a) {
        int n=a.size();
        int l=-1,h=n,pivot=-1;
        while(h-l>1){
            int mid=(h-l)/2+l;
            if(a[mid]>a[n-1])l=mid;
            else h=mid;
        }
        return a[h];
    }
};