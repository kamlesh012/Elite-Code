class Solution {
public:
    int back(vector<int> &sum,vector<int> &ck,int i,int k){
        if(i==ck.size()){
            int mx=0;
            for(auto &i:sum){
                mx=max(mx,i);
            }
            return mx;
        }
        int ans=INT_MAX;
        for(int j=0;j<k;j++){
                sum[j]+=ck[i];
            ans=min(ans,back(sum,ck,i+1,k));
                sum[j]-=ck[i];
        }
        return ans;
    }
    
    int distributeCookies(vector<int>& ck, int k) {
        int n=ck.size();
        vector<int> sum(k,0);
        return back(sum,ck,0,k);
    }
};