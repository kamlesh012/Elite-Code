class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> a,b;
        unordered_map<char,int> ma,mb;
        unordered_set<char> sa,sb;
        for(auto i:word1){
            ma[i]++;
        }
        for(auto i:word2){
            mb[i]++;
        }
        for(auto i:ma)
        {
            sa.insert(i.first);
            a.push_back(i.second);
        }
        for(auto i:mb)
        {
            sb.insert(i.first);
            b.push_back(i.second);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(sa==sb)
        return a==b;
        return false;
        
        }
};