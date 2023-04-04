class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> mp;
        int partition=1;
        for(auto i:s){
            if(mp.find(i)!=mp.end()){
                partition++;
                mp.clear();
            }
                mp[i]++;
        }
        return partition;
    }
};