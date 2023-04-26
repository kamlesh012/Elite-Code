class Solution {
public:
    int addDigits(int num) {
        int rem=0;
        while(num>=10)rem=num%10,num=num/10,num+=rem;
        return num;
    }
};