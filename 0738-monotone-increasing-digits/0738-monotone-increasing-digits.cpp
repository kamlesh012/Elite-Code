class Solution {
public:
    /*
    ===================LOGIC :===================
According to me here we have taken the just previous number of the given number like in 268 we see the pattern "68" decreasing so we try to go one tens digit behind in 50s and to make largest number we put 9 in front of 5 because we need to maximize the answer also . Now if we found any other such mismatch we convert further digits after the mask to 9 .
Let me explain through more examples:

3475 ---- marker at 5 so decrease 7->6 to obtain in 60s and put 9 to get max answer 3469.
3466 --- no effect since all are in increasing pattern
5432 --
iter i) marker at 2 reduce 3->2 to get in 20s (5422)
iter 2) marker at 2(at i=2) again reduce 4->3 to get in 300s ( 5322)
iter 3) marker at 3(ati i=1) again reudces 5->4 to get in 4000s (4322)
now to make our number largest and valid we put 9 in front of the last marker position to get (4999)
    */
    int monotoneIncreasingDigits(int n) {
       string s=to_string(n);
        int l=s.length();
        int marker=l;
        for(int i=l-1;i>0;--i){
            if(s[i]<s[i-1]){
                s[i-1]--;
                marker=i;
            }
        }
        for(int i=marker;i<l;i++){
            s[i]='9';
        }
        int num=stoi(s);
        return num;
    }
};