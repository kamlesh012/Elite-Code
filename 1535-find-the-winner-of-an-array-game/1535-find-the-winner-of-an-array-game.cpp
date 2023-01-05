class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        //Simple Observation :
        //At a current instance in the game
        //The first element that will have at least k smaller elements (consecutively) before or after it will be the winnner.
        //if there is no such element than the max element will be the winner.
        //as in next rounds no one can replace the max element.
        
        int n=arr.size();
        int curr=arr[0];
        int cnt=0,mx=0;
        
        for(int i=1;i<n;i++){
            if(arr[i]<curr)cnt++;
            else{
                curr=arr[i];
                cnt=1;
            }
            if(cnt==k)return curr;
        }
        
        return *max_element(arr.begin(),arr.end());
    }
};