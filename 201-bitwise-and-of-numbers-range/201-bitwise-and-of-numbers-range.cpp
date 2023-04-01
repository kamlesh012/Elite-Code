class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i=0;
        while((1ll<<i)<=right)i++;
        i--;
        
        // Observation:->
        
        //Context of terminologies: 
        //Consider direction of iteration from MSB to LSB(32th bit to 1st bit) 
        //Let x be the first position where bits of left & right differ.
        
        //Claim:
        // Only Set-bits before x will contribute to the answer.
        // The remaining bits after that position will contribute zero to ans.
        
        // WHY? 
        //since we have to take all numbers from left to right 
        //so if there is a bit mismatch b/w left & right it means that
        //a (power of two number) will exist somwehere in between that mismatch bit from left to right.
        
        //and as we know a ((power of two number)&(power of two number -1)) will always be zero.
        //so all the bits from the first mismatch to LSB will be zero.
        
        
        //Approach:-
        //Iterate from MSB to LSB
        //If left & right both have equal bit at current position "OR" to current bit with ans.
        //else break as remaining bits will not contribute to answer;
        
        int ans=0;
        while(i>=0){
            int curr=(1<<i);
            if((curr&right) && (curr&left))ans=ans|curr;
            else if((curr&right) || (curr&left))break;
            i--;
        }
        
        return ans;
    }
};