class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        
        string kamlesh="123456789";
        
        for(int i=0;i<kamlesh.size();i++){    
            
            string singh="";
            
            for(int j=i;j<kamlesh.size();j++){
                singh+=kamlesh[j];
                
                int bisht=stoi(singh);
                
                if(bisht>=low && bisht<=high){
                    ans.push_back(bisht);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};