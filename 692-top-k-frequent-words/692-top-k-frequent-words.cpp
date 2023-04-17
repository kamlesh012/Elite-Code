struct comp{
    bool operator()(const pair<int,string> &a,const pair<int,string> &b){
        //Remember the comparator works inversely in case of priority queue.
        if(a.first==b.first)return a.second>b.second;
        return a.first<b.first;
    }
};

class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> pq;
        map<string,int> mp;
        for(auto i:words){
            mp[i]++;
        }
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        vector<string> ans;
        // while(pq.size()){
        //     auto it=pq.top();
        //     cout<<it.first<<" "<<it.second<<endl;
        //     pq.pop();
        // }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};