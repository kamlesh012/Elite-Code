class Solution {
public:
    int largestAltitude(vector<int>& gain) {
     int sum=0,mx=0;
        for(auto i:gain){
            sum+=i;
            mx=max(mx,sum);
        }
        return mx;
    }
};