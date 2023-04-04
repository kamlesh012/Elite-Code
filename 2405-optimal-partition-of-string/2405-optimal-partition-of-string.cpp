class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> mp;
        int partition=1;
        for(auto i:s){
            // if(mp[i]==partition){
                // partition++;
            // }
            if(mp.find(i)!=mp.end()){
                partition++;
                mp.clear();
            }
                mp[i]++;
        }
        return partition;
    }
};