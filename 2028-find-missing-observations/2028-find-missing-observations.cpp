class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
//         Math
        /*
        csum=sum(rolls)
        (csum+missingsum)/(n+m)=mean
        missingsum=(mean*(n+m))-csum
        */
//         NOw simply distribute this missingsum among n values;
        int m=rolls.size();
        int csum=accumulate(rolls.begin(),rolls.end(),0ll);
        int msum=mean*(n+m)-csum;
        
        int perfect=msum/n;
        int rem=msum%n;
        if(msum<n || msum>6*n)return {};
        vector<int> ans(n,perfect);
        for(int i=0;i<n && rem>0;i++){
            ans[i]++;
            rem--;
        }
        return ans;
    }
};