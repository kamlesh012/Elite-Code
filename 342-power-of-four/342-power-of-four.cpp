class Solution {
public:
    bool isPowerOfFour(int n) {
    if(n<=0)return false;
     if(!(n&(n-1))){
         
         int x=log2(n);
         if((x)%2==1)return false;
         else return true;
     }
        return false;
    }
};