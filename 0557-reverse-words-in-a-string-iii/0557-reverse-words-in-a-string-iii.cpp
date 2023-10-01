class Solution {
public:
    string reverseWords(string s) {
        string reversed;
        int n=s.length(),i=0;
        while(i<n){
            string temp;
            while(i<n && s[i]!=' '){
                temp.push_back(s[i]);
                i++;
            }
            reverse(temp.begin(),temp.end());
            reversed+=temp;
            if(i<n)reversed+=" ";
            i++;
        }
        return reversed;
    }
};