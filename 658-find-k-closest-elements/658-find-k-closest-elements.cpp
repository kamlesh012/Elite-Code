class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //using two pointers
        vector<int> ans;
        int i=0,j=arr.size()-1;
        while(j-i>=k){
            if(abs(arr[i]-x)<=abs(arr[j]-x))j--;
            else i++;
        }
        
        while(i<=j){
            ans.push_back(arr[i]);
            i++;
        }
        
        return ans;
        
        //using minheap
        /*
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto i:arr){
            pq.push({abs(x-i),i});
        }
        
        vector<int> ans;
        for(int i=0;i<k;i++){
            int curr=pq.top().second;
            ans.push_back(curr);
            //ans.insert(curr);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        */
    }
};