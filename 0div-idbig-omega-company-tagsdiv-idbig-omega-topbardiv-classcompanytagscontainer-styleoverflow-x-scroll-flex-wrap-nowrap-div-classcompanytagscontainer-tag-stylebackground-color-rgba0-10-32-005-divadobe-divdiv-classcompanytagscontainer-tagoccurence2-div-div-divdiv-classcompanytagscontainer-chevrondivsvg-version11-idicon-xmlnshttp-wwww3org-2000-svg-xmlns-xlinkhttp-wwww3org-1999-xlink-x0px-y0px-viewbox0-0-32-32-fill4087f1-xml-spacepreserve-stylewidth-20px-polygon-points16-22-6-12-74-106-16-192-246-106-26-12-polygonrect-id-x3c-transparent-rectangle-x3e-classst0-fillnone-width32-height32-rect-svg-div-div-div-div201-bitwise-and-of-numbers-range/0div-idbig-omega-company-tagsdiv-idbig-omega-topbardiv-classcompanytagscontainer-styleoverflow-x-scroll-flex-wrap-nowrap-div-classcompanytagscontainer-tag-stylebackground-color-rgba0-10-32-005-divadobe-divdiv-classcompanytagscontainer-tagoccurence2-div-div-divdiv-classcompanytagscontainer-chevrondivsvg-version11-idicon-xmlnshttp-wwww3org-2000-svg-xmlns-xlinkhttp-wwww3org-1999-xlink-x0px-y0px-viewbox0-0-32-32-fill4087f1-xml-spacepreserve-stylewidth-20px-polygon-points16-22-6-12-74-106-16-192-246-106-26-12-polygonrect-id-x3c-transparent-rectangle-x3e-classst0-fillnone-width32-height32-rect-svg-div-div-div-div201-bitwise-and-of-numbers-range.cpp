class Solution {
public:
    
    int rangeBitwiseAnd(int left, int right) {
        int shiftCount=0;
        while(left!=right)
        {
            left=(left>>1); //right-shift
            right=(right>>1);   //right-shift
            shiftCount++;
        }
        return (left<<shiftCount);  //jina right-shift kiya tha, utna left-shift karenge
    }
};