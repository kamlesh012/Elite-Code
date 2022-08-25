class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26]={0};
        for(auto i:magazine){
            hash[i-'a']++;
        }
        for(auto i:ransomNote){
            hash[i-'a']--;
        }
        for(auto i:hash){
            if(i<0)return false;
        }
        return true;
        
    }
};