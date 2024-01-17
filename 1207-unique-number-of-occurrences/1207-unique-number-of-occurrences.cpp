class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int,int> mp;
        for(auto i:arr){
            mp[i]++;
        }
        unordered_set<int> st;
        for(auto i:mp){
            st.insert(i.second);
        }
        return st.size()==mp.size();
    }
};