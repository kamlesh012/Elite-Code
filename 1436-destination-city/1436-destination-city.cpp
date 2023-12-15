class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        map<string,int>mp;
        for(auto i:paths){
            mp[i[0]]++;
        }
        string ans;
        for(auto i:paths){
            if(!mp.count(i[1])){ans=i[1];break;}
        }
        return ans;
    }
};