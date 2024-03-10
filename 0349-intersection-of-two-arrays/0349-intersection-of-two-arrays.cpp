class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size();
        vector<int> ans;
        int i=0,j=0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        while(i<n && j<m){
            if(a[i]<b[j])i++;
            else if(b[j]<a[i])j++;
            else {
                if(!ans.size() || (ans.size() && ans.back()!=a[i]))ans.push_back(a[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};