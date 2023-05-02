class Solution {
public:
    int arraySign(vector<int>& nums) {
        int z=0,neg=0;
        for(auto i:nums){
            if(!i)z++;
            else if(i<0)neg++;
        }
        if(z)return 0;
        if(neg&1)return -1;
        return 1;
    }
};