class NumArray {
public:
    vector<int> blocks;
    vector<int> num;
    NumArray(vector<int>& nums) {
        num=nums;
        int n=nums.size();
        int bs=sqrt(n+0.0)+1;
        blocks.resize(bs);
        for(int i=0;i<n;i++){
            blocks[i/bs]+=nums[i];
        }
    }
    
    void update(int index, int val) {
        int bs=blocks.size();
        int bl=index/bs;
        blocks[bl]-=num[index];
        num[index]=val;
        blocks[bl]+=num[index];
    }
    
    int sumRange(int left, int right) {
        int bs=num.size();
        bs=sqrt(bs+0.0)+1;
        int sum=0;
        for(int i=left;i<=right;){
            if(i%bs==0 && i+bs-1<=right){
                sum+=blocks[i/bs];
                i+=bs;
            }
            else{
                sum+=num[i];
                i++;
            }
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */