class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i=0;
        while((1ll<<i)<=right)i++;
        i--;
        
        int ans=0;
        while(i>=0){
            if((1<<i)&right && (1<<i)&left)ans=ans|(1<<i);
            else if((1<<i)&right || (1<<i)&left)break;
            i--;
        }
        return ans;
    }
};