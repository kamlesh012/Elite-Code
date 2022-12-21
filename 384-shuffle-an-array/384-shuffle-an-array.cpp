class Solution {
public:
    vector<int> original,array;
    int n;
    Solution(vector<int>& nums) {
        original=nums;
        array=nums;
        n=nums.size();
    }
    
    vector<int> reset() {
        array=original;
        return original;
    }
    
    vector<int> shuffle(){
        // srand(time(0));
        //don't know why not using srand.
    
        for(int i=n-1;i>=0;--i){
            int ind=rand()%(i+1);
            swap(array[i],array[ind]);
        }
        //correct
        
        // for(int i=0;i<n;i++){
        //     int ind=((rand()%n)+i)%n;
        //     swap(array[i],array[ind]);
        // }
        //technically wrong
        return array;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */