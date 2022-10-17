class Solution {
public:
    bool checkIfPangram(string sentence) {
        int hash[26]={0};
        for(auto i:sentence){
            hash[i-'a']++;
        }
        for(auto i:hash){
            if(!i)return false;
        }
        return true;
        
    }
};