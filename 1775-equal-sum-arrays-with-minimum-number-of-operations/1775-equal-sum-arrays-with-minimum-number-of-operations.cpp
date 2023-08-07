class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
       // https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/discuss/1086127/greedy-C%2B%2B-or-O(N)-time-and-O(1)-space-or-short-and-easy-to-understand-or-100-beat
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