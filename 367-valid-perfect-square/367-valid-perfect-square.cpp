class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1)
        {
            return 1;
        }
        int i=1,j=num/2;
        while(i<=j)
        {
            long long mid=i+(j-i)/2;
            long long prod=mid*mid;
            if(prod==num)
            {
                return 1;
            }
            else if(prod<num)
            {
                i=mid+1;
            }
            else
            {
                j=mid-1;
            }
        }
        return 0;
    }
};