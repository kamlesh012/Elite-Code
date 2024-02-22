class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int> not_trusting;
        for(int i=1;i<=n;i++)not_trusting.insert(i);

        vector<int> trusted(n+1,0);
        for(auto i:trust){
            not_trusting.erase(i[0]);
            trusted[i[1]]++;
        }
        
        if(not_trusting.empty())return -1;
        else if(trusted[*not_trusting.begin()]!=n-1)return -1;
        return *not_trusting.begin();
    }
};