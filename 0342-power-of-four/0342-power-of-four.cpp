class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        bool po2=!(n&(n-1));
        int lg=log2(n);
        bool even=!(lg%2);
        return po2&&even;
    }
};