class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        vector<string> power;
        for(int i=0;i<=30;i++){
            power.push_back(to_string(int(pow(2,i))));
        }
        for(auto &i:power){
            sort(i.begin(),i.end());
    
        }
        for(auto i:power){
            if(i==s)return true;
        }
        return false;
        
    }
};