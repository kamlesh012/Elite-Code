class Solution {
public:
    
    int maximumCandies(vector<int>& candies, long long k) {
        long long l=0,h=199999999999999999;
        
        while(h-l>1){
            long long mid=((h-l)/2)+l;
            long long cnt=0;
            for(int i=0;i<candies.size();i++){
                cnt+=(candies[i]/mid);
            }
            if(cnt<k)h=mid;
            else l=mid;
        }
        return l;
    }
};