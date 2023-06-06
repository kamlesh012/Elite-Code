class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& ar) {
        int n=ar.size();
        sort(ar.begin(),ar.end());
        int prev=ar[1]-ar[0];
        for(int i=2;i<n;i++){
            if(ar[i]-ar[i-1]!=prev)return false;
        }
        return true;
    }
};