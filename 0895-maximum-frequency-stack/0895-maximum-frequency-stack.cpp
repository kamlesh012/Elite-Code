class FreqStack {
public:
    unordered_map<int,stack<int>> groups;
    unordered_map<int,int> freq;
    int mxfreq=0;
    FreqStack() {
        
        //Maintaining a map that stores the frequency and all the elements of a particular frequency in separate stacks in the original order of insertion.
        
        //maintinaing a max_freq variable to keep track of the max frequency.
    }
    
    void push(int val) {
        int curr_group=freq[val]+1;
        groups[curr_group].push(val);
        freq[val]++;
        mxfreq=max(mxfreq,freq[val]);
    }
    
    int pop() {
        
        int val=groups[mxfreq].top();
        groups[mxfreq].pop();
        
        if(groups[mxfreq].empty())mxfreq--;
        freq[val]--;
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */