class Solution {
public:
    //Binary Search on Answer
    //Predicate Function
    bool predicate(vector<int>&b,int m,int k,int days){
        int mx=INT_MIN;
        int splits=0,n=b.size(),cnt=0;
        //splits will store the count no. of subarrays of length k in which the max value is smaller than or equal to days.
        for(int i=0;i<n;i++){
            
            //Leetcode's Easy Way
            if(b[i]<=days)cnt++;
            else cnt=0;
            if(cnt==k){
                splits++;
                cnt=0;
            }
            
            //My Hard Way
            // int j=i;
            // for(;j<n && j-i<k;j++){
            //     if(b[j]>days)break;
            // }
            // if(j-i==k){
            //     i=j;
            //     splits++;
            // }
            // else i=j+1;
        }
        return splits>=m;
    }
    
    int minDays(vector<int>& b, int m, int k) {
        int l=-1,h=*max_element(b.begin(),b.end())+1;
        int oh=h;
        while(h-l>1){
            int mid=(h-l)/2+l;
            if(predicate(b,m,k,mid))h=mid;
            else l=mid;
        }
        //h==oh means that our h is not changed yet ,that means answer is not possible.
        if(h==oh)h=-1;
        return h;
    }
};