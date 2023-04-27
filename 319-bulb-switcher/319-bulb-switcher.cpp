class Solution {
public:
    int bulbSwitch(int n) {
        /*My code
        int ans=0;
        while((ans*ans)<=n){
            ans++;
        }
        return ans-1;
        */
        //Editorialist's COde
        return sqrt(n);
    }
};