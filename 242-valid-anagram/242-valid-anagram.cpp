class Solution {
public:
    bool isAnagram(string s, string t) {
            
        int hash1[26]={0};
        int hash2[26]={0};
        
        for(auto i:s){
            hash1[i-97]++;
        }
        for(auto i:t){
            hash2[i-97]++;
        }
        for(int i=0;i<26;i++){
            if(hash1[i]!=hash2[i])return false;
        }
        return true;
    }
};