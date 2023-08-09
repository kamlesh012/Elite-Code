class Solution {
public:
    int getMinSwaps(string s, int k) {
            string temp=s;
        for(int i=0;i<k;i++){
            next_permutation(temp.begin(),temp.end());
        }
        
        int cnt=0,n=s.length();
        for(int i=0;i<n;i++){
            if(temp[i]!=s[i]){
                int j=i;
                while(temp[i]!=s[j])j++;
                while(j>i){
                    swap(s[j],s[j-1]);
                    cnt++;
                    j--;
                }
            }
        }
        return cnt;
    }
//     https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/discuss/1186818/C%2B%2B-Detailed-explanation-using-next_permutation
};