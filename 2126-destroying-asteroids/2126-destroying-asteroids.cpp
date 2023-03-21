class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long long ans=mass;
        for(auto i:a){
            if(ans<i)return false;
            ans+=i;
        }
        return true;
    }
};