class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int ans=0;
        int i=0,j=n-2;
        while(i<j){
            ans+=piles[j];
            j-=2;
            i++;
        }
        return ans;
    }
};