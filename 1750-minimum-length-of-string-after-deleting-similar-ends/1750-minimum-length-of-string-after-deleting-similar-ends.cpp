class Solution {
public:
    int minimumLength(string s) {
//         "bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb"
        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
         char first=s[i],last=s[j];
            while(i<=j && s[i]==last)i++;
            while(j>i && s[j]==first)j--;
            // cout<<i<<" "<<j<<endl;
            // cout<<s[i]<<" "<<s[j]<<endl;
            if(i==j || s[i]!=s[j])break;
            // else i++,j--;
        }
        // if(i==j)return 0;
        return j-i+1;
    }
};