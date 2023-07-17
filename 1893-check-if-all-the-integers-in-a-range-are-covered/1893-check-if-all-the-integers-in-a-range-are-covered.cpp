class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int hash[100]={0};
        for(auto i:ranges){
            hash[i[0]]++;
            hash[i[1]+1]--;
        }
        for(int i=1;i<100;i++){
            hash[i]+=hash[i-1];
        }
        while(left<=right){
            if(!hash[left])return false;
            left++;
        }
        return true;
    }
};