class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,ele=0;
        for(auto &i:nums){
            if(!cnt){
                ele=i;
                cnt++;
            }
            else if(i==ele)cnt++;
            else cnt--;
        }
        return ele;
    }
};