class Solution {
public:
    int largestInteger(int num) {
        string s=to_string(num);
        string even,odd;
        for(auto i:s){
            if((i-'0')&1)odd.push_back(i);
            else even.push_back(i);
        }
        sort(odd.rbegin(),odd.rend());
        sort(even.rbegin(),even.rend());
        string ans;
        int i=0,j=0,k=0;
        while(i<odd.size() || j<even.size()){
            if((s[k]-'0')&1)ans.push_back(odd[i++]);
            else ans.push_back(even[j++]);
            k++;
        }
        return stoi(ans);
    }
};