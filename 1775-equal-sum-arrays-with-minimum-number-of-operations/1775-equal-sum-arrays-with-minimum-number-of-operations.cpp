class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        
        int s1=accumulate(a.begin(),a.end(),0);
        int s2=accumulate(b.begin(),b.end(),0);
        if(s1>s2){
            swap(s1,s2);
            swap(a,b);
        }
        int diff=s2-s1;
        if(!diff)return diff;
        vector<int> arr;
        for(auto i:a){
            arr.push_back(6-i);
        }
        for(auto i:b){
            arr.push_back(i-1);
        }
        sort(arr.rbegin(),arr.rend());
        int cnt=0;
        for(auto i:arr){
            cnt++;
            diff-=i;
            if(diff<=0)return cnt;
        }
        return -1;
    }
};