class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i=0,j=0;
        
        while(i<nums1.size() || j<nums2.size()){
            if(i<nums1.size() && j<nums2.size() && nums1[i]<nums2[j]){
                arr.push_back(nums1[i++]);
            }
            else if(i<nums1.size() && j<nums2.size() && nums1[i]>=nums2[j]){
                arr.push_back(nums2[j++]);
            }
            else if(i<nums1.size()) arr.push_back(nums1[i++]);
            else arr.push_back(nums2[j++]);
        }
        
        int n=arr.size();
        double ans=0;
        if(n%2!=0)return arr[n/2];
        else{
            ans=(arr[n/2]+arr[(n/2)-1])/2.0;
        }
        return ans;
    }
};