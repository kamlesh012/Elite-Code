class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        //Non-Overlapping Intervals/Disjoint INtervals.
        //the min no.of interals to remove to make all remainign intervals non-overlapping.
        
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
                //First & Last indexes of All the characters that are in between the boundary needs to be found to expand current range.
                //if a middle character has last index to right of boundary increase the rigt boundary
                //Don't consider if a character voilates left boundary as that substring would already have been added.
                for (int j = b; j <= e; j++) {
                    b = min(b, fst[s[j] - 'a']);
                    e = max(e, lst[s[j] - 'a']);
                }
                if (b == fst[i]) {
                    merged.emplace_back(b,e);
                }
            }
        }

        //Now it is standard -Non Overlapping INtervals Problem.
        sort(merged.begin(),merged.end(),[&](pair<int,int> &a,pair<int,int> &b){
            return a.second<b.second;
        });
        
        vector<string> ans;
        int start=merged[0].first,end=merged[0].second;
        for(int i=1;i<merged.size();i++){
            if(merged[i].first>end){
                ans.emplace_back(s.substr(start,end-start+1));
                start=merged[i].first;
                end=merged[i].second;
            }
        }
        ans.push_back(s.substr(start,end-start+1));
        return ans;
    }
};