class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n=a.size();
        int curr=0,mx=INT_MIN,mxsum=INT_MIN;
        for(int i=0;i<n;i++){
            if(a[i]+curr>=a[i]){
                curr+=a[i];
            }
            else{
                curr=a[i];
            }
            mxsum=max(mxsum,curr);
        }
        return mxsum;
    }
};