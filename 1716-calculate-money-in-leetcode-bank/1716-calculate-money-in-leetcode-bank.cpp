class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int start=0;
        int cnt=1;
        for(int i=0;i<n;i++){
            if(i%7==0){
                start++;
                cnt=start;
            }
            ans+=cnt;
            cnt++;
        }
        return ans;
    }
};