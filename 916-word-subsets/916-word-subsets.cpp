class Solution {
public:
        vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int count[26] = {0};
        for(string &w2 : words2){
            int count2[26] = {0};
            for(char ch : w2){
                count2[ch-97]++;
                count[ch-97] = max(count[ch-97], count2[ch-97]);
            }
        }
        vector<string> res;
        for(string &w1 : words1){
            int count2[26] = {0};
            for(char ch : w1){
                count2[ch-97]++;
            }
            for(int i = 0; i<=26; i++){
                if(i==26){
                    res.push_back(w1);
                    break;
                }
                if(count[i]>count2[i]) break;
            }
        }
        return res;
    }
};