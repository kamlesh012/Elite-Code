class Solution {
public:
    long long maximumSumOfHeights(vector<int>& mh) {
        int n=mh.size();
        long long ans=0ll,sum=0ll;
        for(int i=0;i<n;i++){
            sum=mh[i];
            int mn=mh[i];
            for(int j=i-1;j>=0;--j){
                mn=min(mn,mh[j]);
                sum+=mn;
            }
            mn=mh[i];
            // cout<<" Left "<<sum<<endl;
            for(int j=i+1;j<n;j++){
                mn=min(mn,mh[j]);
                sum+=mn;
            }
            ans=max(ans,sum);
            // cout<<"right "<<sum<<endl;
        }
        return ans;
    }
};