class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> start,end;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(!start.count(s[i]))start[s[i]]=i+1;
            end[s[i]]=i+1;
        }
        vector<pair<int,int>> intervals;
        for(int i=0;i<26;i++){
            char c=i+'a';
            if(start[c])
            intervals.push_back({start[c],end[c]});
        }
        sort(intervals.begin(),intervals.end(),[&](pair<int,int> &a,pair<int,int> &b){
            if(a.first==b.first)return a.second<b.second;
            return a.first<b.first;
        });
        int strt=intervals[0].first,endd=intervals[0].second;
        
        vector<int> ans;
        
        for(int i=1;i<intervals.size();i++){
            if(endd<intervals[i].first){
                ans.push_back(endd-strt+1);
                strt=intervals[i].first;
                endd=intervals[i].second;
            }
            else{
                endd=max(endd,intervals[i].second);
            }
        }
        ans.push_back(endd-strt+1);
        return ans;
            
    }
};