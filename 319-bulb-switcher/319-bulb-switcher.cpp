class Solution {
public:
    int bulbSwitch(int n) {
        int ans=0;
        while((ans*ans)<=n){
            ans++;
        }
        return ans-1;
    }
};