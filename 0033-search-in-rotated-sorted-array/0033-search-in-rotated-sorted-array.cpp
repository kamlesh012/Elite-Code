class Solution {
public:
    int search(vector<int>& a, int target) {
        int n=a.size();
        int l=-1,h=n,pivot=-1;
        while(h-l>1){
            int mid=(h-l)/2+l;
            if(a[mid]>a[n-1])l=mid;
            else h=mid;
        }
        pivot=h;
        cout<<pivot<<" pivot "<<a[pivot]<<endl;
        
        if(target>=a[pivot] && target<=a[n-1])l=pivot-1,h=n;
        else l=-1,h=pivot;
        
        
        while(h-l>1){
            int mid=(h-l)/2+l;
            if(a[mid]<target)l=mid;
            else h=mid;
        }
        // cout<<l<<" ans" <<h<<endl;
        if(a[h]!=target)h=-1;
        // if(h==l)h=-1;
        return h;
        
    }
};