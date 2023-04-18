class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int n=word1.length(),m=word2.length();
        int i=0,j=0;
        while(i<n || j<m){
            if(i<n){
                ans.push_back(word1[i++]);
            }
            if(j<m){
                ans.push_back(word2[j++]);
            }
        }
        return ans;
    }
};