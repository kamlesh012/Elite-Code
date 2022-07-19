class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev(1,1);
        for(int x=0;x<rowIndex;x++){
            vector<int> curr;
            curr.push_back(prev[0]);
            int i=1;
            while(i<prev.size()){
                curr.push_back(prev[i-1]+prev[i]);
                i++;
            }
            curr.push_back(prev[i-1]);
            prev=curr;
        }
        return prev;
    }
};