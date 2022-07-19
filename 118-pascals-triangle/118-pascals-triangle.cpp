class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> prev(1,1);
        v.push_back(prev);
        for(int x=1;x<numRows;x++){
            vector<int> curr;
            curr.push_back(prev[0]);
            int i=1;
            while(i<prev.size()){
                curr.push_back(prev[i-1]+prev[i]);
                i++;
            }
            curr.push_back(prev[i-1]);
            v.push_back(curr);
            prev=curr;
        }
        return v;
    }
};