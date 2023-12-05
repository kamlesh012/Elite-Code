class Solution {
public:
    int numberOfMatches(int n) {
        int ans=0;
        while(n>1){
            int matches=0;
            if(n&1){
                matches=(n-1)/2;
                n=(n+1)/2;
            }
            else{
                matches=n/2;
                n/=2;
            }
            ans+=matches;
        }
        return ans;
    }
};