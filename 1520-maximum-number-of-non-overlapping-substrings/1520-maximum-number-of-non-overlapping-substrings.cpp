class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        //Non-Overlapping INtervals/Disjoint INtervals.
        //the min no.of interals to remove to make all remainign intervals non-overlapping.
        
//         unordered_map<char,int> strt,endd;
//         int n=s.length();
//         for(int i=0;i<n;i++){
//             if(!strt.count(s[i]))strt[s[i]]=i;
//             endd[s[i]]=i;
//         }
        
//         vector<pair<int,int>> intervals;
//         for(int i=0;i<26;i++){
//             char c=i+'a';
//             if(strt[c] || endd[c])
//             intervals.push_back({strt[c],endd[c]});
//         }
//         sort(intervals.begin(),intervals.end(),[&](pair<int,int> &a,pair<int,int> &b){
//             if(a.first==b.first)return a.second<b.second;
//             return a.first<b.first;
//         });
        
//         cout<<"INTERVAlS "<<endl;
//         for(auto i:intervals){
//             cout<<i.first<<" "<<i.second<<endl;
//         }
//         vector<pair<int,int>> merged;
//         int f=intervals[0].first,sec=intervals[0].second;
        
//         for(int i=1;i<intervals.size();i++){
//             if(sec<intervals[i].first){
//                 merged.push_back({f,sec});
//                 f=intervals[i].first;
//                 sec=intervals[i].second;
//             }
//             else{
//                 //If a interval overlaps current interval but it is completely between the boundary
//                 //then this interval can be one of the possible answers.
//                 //so add it to the list of valid intervals as well.
//                 if(intervals[i].first>f && intervals[i].second<sec)
//                     merged.push_back({intervals[i].first,intervals[i].second});
                
//                 sec=max(sec,intervals[i].second);
//             }
//         }
        
//        // ans.push_back(endd-strt+1);
//         merged.push_back({f,sec});
        
//          sort(merged.begin(),merged.end(),[&](pair<int,int> &a,pair<int,int> &b){
//             return a.second<b.second;
//         });
//         cout<<"Merged "<<endl;
//         for(auto i:merged){
//             cout<<i.first<<" "<<i.second<<endl;
//         }
        
        int n = s.length();
        
        vector<int> fst(26, INT_MAX);
        vector<int> lst(26, INT_MIN);
        for (int i = 0; i < n; i++) {
            fst[s[i] - 'a'] = min(fst[s[i] - 'a'], i);
            lst[s[i] - 'a'] = max(lst[s[i] - 'a'], i);
        }
        
        vector<pair<int, int>> merged;
        for (int i = 0; i < 26; i++) {
            if (fst[i] < n) {
                int b = fst[i];
                int e = lst[i];
                //First & Last indexes of All the characters that are in between the boundary needs to be found to expand current range to right if possible.
                //won't consider if a character voilates left boundary as that substring would already have been added.
                for (int j = b; j <= e; j++) {
                    b = min(b, fst[s[j] - 'a']);
                    e = max(e, lst[s[j] - 'a']);
                }
                if (b == fst[i]) {
                    merged.emplace_back(b,e);
                }
            }
        }
        // // cout<<endl;
        // for(auto i:merged){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        sort(merged.begin(),merged.end(),[&](pair<int,int> &a,pair<int,int> &b){
            return a.second<b.second;
        });
        vector<string> ans;
        int start=merged[0].first,end=merged[0].second;
        for(int i=1;i<merged.size();i++){
            if(merged[i].first>end){
                ans.push_back(s.substr(start,end-start+1));
                start=merged[i].first;
                end=merged[i].second;
            }
        }
        ans.push_back(s.substr(start,end-start+1));
        return ans;
    }
};