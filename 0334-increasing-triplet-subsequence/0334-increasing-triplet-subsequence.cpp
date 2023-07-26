class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        //Just need to check if there exists a LIS of length >=3
        vector<int> take;
        for(auto i:a){
            if(take.empty() || take.back()<i){
                take.push_back(i);
            }
            else{
                auto it=lower_bound(take.begin(),take.end(),i);
                take[it-take.begin()]=i;
            }
        }
        return take.size()>=3;
    }
};