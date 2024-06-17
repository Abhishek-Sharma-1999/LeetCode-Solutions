class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int a=0,b=(long)sqrt(c);
        while(a<=b)
        {
            long long int sum=(a*a)+(b*b); 
            if(sum==c)
                return true;
            else if(sum<c)
                a++;
            else
                b--;
        }
        return false;
    }
};