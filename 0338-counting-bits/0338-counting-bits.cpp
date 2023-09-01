class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
            int j=0;
            int cnt=0;
            while((1<<j)<=i){
                if((1<<j)&i)cnt++;
                j++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};