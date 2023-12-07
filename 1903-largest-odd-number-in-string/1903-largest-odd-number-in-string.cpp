class Solution {
public:
    string largestOddNumber(string num) {
        int ind=-1;
        for(int i=num.length()-1;i>=0;--i){
            if(num[i]&1){
                ind=i+1;
                break;
            }
        }
        string empty="";
        if(ind!=-1){
            empty=num.substr(0,ind);
        }
        return empty;
        
    }
};