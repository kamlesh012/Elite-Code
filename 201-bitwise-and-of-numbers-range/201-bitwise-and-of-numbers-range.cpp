class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i=0;
        while((1ll<<i)<=right)i++;
        i--;
        
        int ans=0;
        while(i>=0){
            int curr=(1<<i);
            if((curr&right) && (curr&left))ans=ans|curr;
            else if((curr&right) || (curr&left))break;
            i--;
        }
        return ans;
    }
};