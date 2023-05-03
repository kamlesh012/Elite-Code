class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> v(2);
        set<int> n1(nums1.begin(),nums1.end());
        set<int> n2(nums2.begin(),nums2.end());
        for(auto i:n1){
            int f=0;
            for(auto j:nums2){
                if(i==j){f++;break;}
            }
            if(!f)v[0].push_back(i);
        }
        
        for(auto i:n2){
            int f=0;
            for(auto j:nums1){
                if(i==j){f++;break;}
            }
            if(!f)v[1].push_back(i);
        }
        
        return v;
    }
};
