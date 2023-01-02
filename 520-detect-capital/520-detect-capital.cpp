class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0,ind=-1;
        
        for(int i=0;i<word.length();i++){
            // (word[i]>=61 && word[i]<=91)?{cnt++;ind=i;}:{cnt=cnt;}
            if(word[i]>=61 && word[i]<=91){cnt++;ind=i;}
            else{cnt=cnt;}
        }
        return (!cnt || (cnt==1 && ind==0) || cnt==word.length())?true:false;
    }
};