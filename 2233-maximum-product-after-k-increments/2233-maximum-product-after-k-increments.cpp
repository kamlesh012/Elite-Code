class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,greater<int>> pq;
        for(auto i:nums){
            pq.push(i);
            }
        
        while(k){
            int x=pq.top();
            pq.pop();
            x++;
            pq.push(x);
            k--;
        }
        long long int prod=1,md=1e9+7;
        while(!pq.empty()){
            int i=pq.top();
            prod=((prod%md)*(i%md))%md;
            pq.pop();
        }
        return prod;
    }
};