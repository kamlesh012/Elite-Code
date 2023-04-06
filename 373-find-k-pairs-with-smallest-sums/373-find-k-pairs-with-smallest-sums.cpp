class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //Saw a comment in most Voted C++ Solution. on Discuss.
        //Link for the post:
        //https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/596658/C%2B%2B-solution-with-diagram-explaination-for-beginners
        priority_queue<pair<int,pair<int,int>>> q;
        int n=nums1.size(),m=nums2.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=nums1[i]+nums2[j];
                if(q.size()<k){
                    q.push({sum,{nums1[i],nums2[j]}});
                }
                else if(q.top().first>sum){
                    q.pop();
                    q.push({sum,{nums1[i],nums2[j]}});
                }
                else break;
            }
        }
        
        vector<vector<int>> ans;
        while(q.size()){
            ans.push_back({q.top().second.first,q.top().second.second});
            q.pop();
        }
        return ans;
    }
};