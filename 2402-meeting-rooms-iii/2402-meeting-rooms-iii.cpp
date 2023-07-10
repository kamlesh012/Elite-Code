#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meet) {
        
  //Figured out the initial apporach but implemented the wrong way in the first go.
        
        map<int,int> freq;
        priority_queue<int,vector<int>,greater<int>> free;
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> occupied;
        
        sort(meet.begin(),meet.end(),[&](vector<int> &a,vector<int> &b){
            return a[0]<b[0];
        });
        
        for(int i=0;i<n;i++){
            free.push(i);
        }
        
        for(int i=0;i<meet.size();i++){
            ll start=meet[i][0];
            ll end=meet[i][1];
            while(occupied.size() && occupied.top().first<=start){
                pair<int,int> curr=occupied.top();
                occupied.pop();
                free.push(curr.second);
            }
            
            if(free.size()){
                int room=free.top();
                free.pop();
                freq[room]++;
                occupied.push({end,room});
            }
            else{
                int room=occupied.top().second;
                ll oldEndTime=occupied.top().first;
                occupied.pop();
                
                freq[room]++;
                ll newEndTime=end-start+(oldEndTime);
                occupied.push({newEndTime,room});
            }
        }
        
        int mx=0,mxn=0;
        for(auto i:freq){
            if(i.second>mx){
                mx=i.second;
                mxn=i.first;
            }
        }
        
        return mxn;
    }
};